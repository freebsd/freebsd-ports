Index: cli/task_runner.rs
--- cli/task_runner.rs.orig
+++ cli/task_runner.rs
@@ -243,7 +243,8 @@ impl ShellCommand for NpmCommand {
       );
       return ExecutableCommand::new(
         "deno".to_string(),
-        std::env::current_exe().unwrap(),
+        std::env::current_exe()
+          .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
       )
       .execute(ShellCommandContext {
         args,
@@ -307,12 +308,16 @@ impl ShellCommand for NodeCommand {
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
+        .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
+    )
+    .execute(ShellCommandContext {
+      args,
+      state,
+      ..context
+    })
   }
 }
 
@@ -400,7 +405,8 @@ impl ShellCommand for NpmPackageBinCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
     );
     executable_command.execute(ShellCommandContext { args, ..context })
   }
@@ -427,7 +433,8 @@ impl ShellCommand for NodeModulesFileRunCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
     );
     // set this environment variable so that the launched process knows the npm command name
     context.state.apply_env_var(
