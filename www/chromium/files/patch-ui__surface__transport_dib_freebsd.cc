--- /dev/null	2011-06-28 23:33:00.000000000 +0300
+++ ui/surface/transport_dib_freebsd.cc	2011-06-28 23:30:26.428806593 +0300
@@ -0,0 +1,107 @@
+// Copyright (c) 2011 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "ui/surface/transport_dib.h"
+
+#include <unistd.h>
+#include <sys/stat.h>
+
+#include "base/eintr_wrapper.h"
+#include "base/logging.h"
+#include "base/memory/scoped_ptr.h"
+#include "base/shared_memory.h"
+#include "skia/ext/platform_canvas.h"
+
+TransportDIB::TransportDIB()
+    : size_(0) {
+}
+
+TransportDIB::TransportDIB(TransportDIB::Handle dib)
+    : shared_memory_(dib, false /* read write */),
+      size_(0) {
+}
+
+TransportDIB::~TransportDIB() {
+}
+
+// static
+TransportDIB* TransportDIB::Create(size_t size, uint32 sequence_num) {
+  TransportDIB* dib = new TransportDIB;
+  if (!dib->shared_memory_.CreateAndMapAnonymous(size)) {
+    delete dib;
+    return NULL;
+  }
+
+  dib->size_ = size;
+  return dib;
+}
+
+// static
+TransportDIB* TransportDIB::Map(Handle handle) {
+  scoped_ptr<TransportDIB> dib(CreateWithHandle(handle));
+  if (!dib->Map())
+    return NULL;
+  return dib.release();
+}
+
+// static
+TransportDIB* TransportDIB::CreateWithHandle(Handle handle) {
+  return new TransportDIB(handle);
+}
+
+// static
+bool TransportDIB::is_valid_handle(Handle dib) {
+  return dib.fd >= 0;
+}
+
+// static
+bool TransportDIB::is_valid_id(Id id) {
+  return id != 0;
+}
+
+skia::PlatformCanvas* TransportDIB::GetPlatformCanvas(int w, int h) {
+  if (!memory() && !Map())
+    return NULL;
+  scoped_ptr<skia::PlatformCanvas> canvas(new skia::PlatformCanvas);
+  if (!canvas->initialize(w, h, true, reinterpret_cast<uint8_t*>(memory())))
+    return NULL;
+  return canvas.release();
+}
+
+bool TransportDIB::Map() {
+  if (!is_valid_handle(handle()))
+    return false;
+  if (memory())
+    return true;
+
+  struct stat st;
+  if ((fstat(shared_memory_.handle().fd, &st) != 0) ||
+      (!shared_memory_.Map(st.st_size))) {
+    return false;
+  }
+
+  size_ = st.st_size;
+  return true;
+}
+
+void* TransportDIB::memory() const {
+  return shared_memory_.memory();
+}
+
+TransportDIB::Id TransportDIB::id() const {
+  return shared_memory_.id();
+}
+
+TransportDIB::Handle TransportDIB::handle() const {
+  return shared_memory_.handle();
+}
+
+XID TransportDIB::MapToX(Display* display) {
+  if (!x_shm_) {
+    x_shm_ = ui::AttachSharedMemory(display, key_);
+    display_ = display;
+  }
+
+  return x_shm_;
+}
