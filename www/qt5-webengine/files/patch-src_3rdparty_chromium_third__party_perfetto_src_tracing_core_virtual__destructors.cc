Backport of:

From 46f0abc66c1d78c60a0415c5cb46852ef3bfa9bb Mon Sep 17 00:00:00 2001
From: Nico Weber <thakis@chromium.org>
Date: Sat, 8 Feb 2020 21:26:53 -0500
Subject: [PATCH] Fix compile error emitted by trunk clang

../../third_party/perfetto/src/tracing/core/virtual_destructors.cc:33:35:
error: destructor cannot be declared using a type alias
    'perfetto::TracingService::ConsumerEndpoint' (aka
    'perfetto::ConsumerEndpoint') of the class name
TracingService::ConsumerEndpoint::~ConsumerEndpoint() = default;

Bug: chromium:1050372
Change-Id: Icc1a8cca06b72ee3322924dc0825ebb62086f730

--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/virtual_destructors.cc.orig	2020-08-24 08:13:26 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/virtual_destructors.cc
@@ -30,8 +30,8 @@ namespace perfetto {
 Consumer::~Consumer() = default;
 Producer::~Producer() = default;
 TracingService::~TracingService() = default;
-TracingService::ConsumerEndpoint::~ConsumerEndpoint() = default;
-TracingService::ProducerEndpoint::~ProducerEndpoint() = default;
+ConsumerEndpoint::~ConsumerEndpoint() = default;
+ProducerEndpoint::~ProducerEndpoint() = default;
 SharedMemory::~SharedMemory() = default;
 SharedMemory::Factory::~Factory() = default;
 SharedMemoryArbiter::~SharedMemoryArbiter() = default;
