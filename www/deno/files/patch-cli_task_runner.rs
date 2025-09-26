Index: cli/task_runner.rs
--- cli/task_runner.rs.orig
+++ cli/task_runner.rs
@@ -248,7 +248,8 @@ impl ShellCommand for NpmCommand {
       );
       return ExecutableCommand::new(
         "deno".to_string(),
-        std::env::current_exe().unwrap(),
+        std::env::current_exe()
+          .unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno")),
       )
       .execute(ShellCommandContext {
         args,
@@ -277,7 +278,8 @@ impl Default for DenoCommand {
   fn default() -> Self {
     Self(ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+          .unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno")),
     ))
   }
 }
@@ -326,12 +328,16 @@ impl ShellCommand for NodeCommand {
       OsStr::new(USE_PKG_JSON_HIDDEN_ENV_VAR_NAME),
       OsStr::new("1"),
     );
-    ExecutableCommand::new("deno".to_string(), std::env::current_exe().unwrap())
-      .execute(ShellCommandContext {
-        args,
-        state,
-        ..context
-      })
+    ExecutableCommand::new(
+      "deno".to_string(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno")),
+    )
+    .execute(ShellCommandContext {
+      args,
+      state,
+      ..context
+    })
   }
 }
 
@@ -425,7 +431,8 @@ impl ShellCommand for NpmPackageBinCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno")),
     );
     executable_command.execute(ShellCommandContext { args, ..context })
   }
@@ -452,7 +459,8 @@ impl ShellCommand for NodeModulesFileRunCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("PREFIX/bin/deno")),
     );
     // set this environment variable so that the launched process knows the npm command name
     context.state.apply_env_var(
