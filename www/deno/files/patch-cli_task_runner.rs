Index: cli/task_runner.rs
--- cli/task_runner.rs.orig
+++ cli/task_runner.rs
@@ -231,7 +231,8 @@ impl ShellCommand for NpmCommand {
       state.apply_env_var(USE_PKG_JSON_HIDDEN_ENV_VAR_NAME, "1");
       return ExecutableCommand::new(
         "deno".to_string(),
-        std::env::current_exe().unwrap(),
+        std::env::current_exe()
+          .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
       )
       .execute(ShellCommandContext {
         args,
@@ -287,12 +288,16 @@ impl ShellCommand for NodeCommand {
     let mut state = context.state;
 
     state.apply_env_var(USE_PKG_JSON_HIDDEN_ENV_VAR_NAME, "1");
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
 
@@ -374,7 +379,8 @@ impl ShellCommand for NpmPackageBinCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
     );
     executable_command.execute(ShellCommandContext { args, ..context })
   }
@@ -401,7 +407,8 @@ impl ShellCommand for NodeModulesFileRunCommand {
     args.extend(context.args);
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
-      std::env::current_exe().unwrap(),
+      std::env::current_exe()
+        .unwrap_or_else(|_| PathBuf::from("LOCALBASE/bin/deno")),
     );
     // set this environment variable so that the launched process knows the npm command name
     context
