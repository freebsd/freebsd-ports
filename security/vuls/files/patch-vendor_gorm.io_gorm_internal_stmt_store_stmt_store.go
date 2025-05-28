commit 8c4e8e2d2a63ef019048bd988a2016948605920b
Author: iTanken <23544702+iTanken@users.noreply.github.com>
Date:   Sun Apr 27 14:05:16 2025 +0800

    fix: int type variable defaultMaxSize overflows in 32-bit environment (#7439)
    
    Refs: #7435

diff --git a/internal/stmt_store/stmt_store.go b/internal/stmt_store/stmt_store.go
index 7068419..a82b2cf 100644
--- vendor/gorm.io/gorm/internal/stmt_store/stmt_store.go
+++ vendor/gorm.io/gorm/internal/stmt_store/stmt_store.go
@@ -3,6 +3,7 @@ package stmt_store
 import (
 	"context"
 	"database/sql"
+	"math"
 	"sync"
 	"time"
 
@@ -73,7 +74,7 @@ type Store interface {
 // the cache can theoretically store as many elements as possible.
 // (1 << 63) - 1 is the maximum value that an int64 type can represent.
 const (
-	defaultMaxSize = (1 << 63) - 1
+	defaultMaxSize = math.MaxInt
 	// defaultTTL defines the default time-to-live (TTL) for each cache entry.
 	// When the TTL for cache entries is not specified, each cache entry will expire after 24 hours.
 	defaultTTL = time.Hour * 24
