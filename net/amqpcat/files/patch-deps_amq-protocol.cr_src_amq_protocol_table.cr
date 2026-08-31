--- deps/amq-protocol.cr/src/amq/protocol/table.cr.orig	2026-08-28 19:19:33 UTC
+++ deps/amq-protocol.cr/src/amq/protocol/table.cr
@@ -219,7 +219,7 @@ module AMQ
 
       def self.from_bytes(bytes, format) : self
         size = format.decode(UInt32, bytes[0, 4])
-        mem = IO::Memory.new(bytes[4, size], writeable: false)
+        mem = IO::Memory.new(bytes[4, size], writable: false)
         new(mem)
       end
 
@@ -227,14 +227,14 @@ module AMQ
         size ||= UInt32.from_io(io, format)
         case io
         when IO::Memory
-          if io.@writeable
+          if io.@writable
             mem = IO::Memory.new(size)
             IO.copy(io, mem, size)
             new(mem)
           else
             bytes = io.to_slice[io.pos, size]
             io.pos += size
-            new(IO::Memory.new(bytes, writeable: false))
+            new(IO::Memory.new(bytes, writable: false))
           end
         else
           mem = IO::Memory.new(size)
@@ -277,7 +277,7 @@ module AMQ
       end
 
       private def ensure_writeable
-        return if @io.@writeable.as(Bool)
+        return if @io.@writable.as(Bool)
         writeable_io = IO::Memory.new(@io.bytesize)
         writeable_io.write @io.to_slice
         @io = writeable_io
