Index: cli/task_runner.rs
--- cli/task_runner.rs.orig	2026-07-01 13:28:43 UTC
+++ cli/task_runner.rs
@@ -328,9 +328,8 @@ impl ShellCommand for NpmCommand {
       );
       return ExecutableCommand::new(
         "deno".to_string(),
-        std::env::current_exe()
-          .and_then(|p| canonicalize_path(&p))
-          .unwrap(),
+          std::env::current_exe()
+            .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
       )
       .execute(ShellCommandContext {
         args,
@@ -360,8 +359,7 @@ impl Default for DenoCommand {
     Self(ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| canonicalize_path(&p))
-        .unwrap(),
+         .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     ))
   }
 }
@@ -413,8 +411,7 @@ impl ShellCommand for NodeCommand {
     ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| canonicalize_path(&p))
-        .unwrap(),
+        .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     )
     .execute(ShellCommandContext {
       args,
@@ -513,8 +510,7 @@ impl ShellCommand for NodeModulesFileRunCommand {
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| canonicalize_path(&p))
-        .unwrap(),
+        .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     );
     // set this environment variable so that the launched process knows the npm command name
     context.state.apply_env_var(
