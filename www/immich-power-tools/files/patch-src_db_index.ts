--- src/db/index.ts.orig	2026-11-06 18:30:06 UTC
+++ src/db/index.ts
@@ -1,6 +1,6 @@
-import { createClient } from "@libsql/client";
-import { drizzle } from "drizzle-orm/libsql";
-import { migrate } from "drizzle-orm/libsql/migrator";
+import Database from "better-sqlite3";
+import { drizzle } from "drizzle-orm/better-sqlite3";
+import { migrate } from "drizzle-orm/better-sqlite3/migrator";
 import fs from "fs";
 import path from "path";
 import * as schema from "./schema";
@@ -10,14 +10,14 @@ fs.mkdirSync(path.dirname(DB_PATH), { recursive: true 
 
 fs.mkdirSync(path.dirname(DB_PATH), { recursive: true });
 
-const client = createClient({ url: `file:${DB_PATH}` });
+const client = new Database(DB_PATH);
 
 export const appDb = drizzle(client, { schema });
 
 // Run pending migrations automatically on startup.
 // migrate() is idempotent — safe to call on every boot.
 export async function runMigrations() {
-  await migrate(appDb, {
+  migrate(appDb, {
     migrationsFolder: path.join(process.cwd(), "src", "db", "migrations"),
   });
 }
