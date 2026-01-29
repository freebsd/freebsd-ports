Index: cli/task_runner.rs
--- cli/task_runner.rs.orig
+++ cli/task_runner.rs
@@ -245,9 +245,8 @@ impl ShellCommand for NpmCommand {
       );
       return ExecutableCommand::new(
         "deno".to_string(),
-        std::env::current_exe()
-          .and_then(|p| p.canonicalize())
-          .unwrap(),
+          std::env::current_exe()
+            .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
       )
       .execute(ShellCommandContext {
         args,
@@ -277,8 +276,7 @@ impl Default for DenoCommand {
     Self(ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| p.canonicalize())
-        .unwrap(),
+        .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     ))
   }
 }
@@ -330,8 +328,7 @@ impl ShellCommand for NodeCommand {
     ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| p.canonicalize())
-        .unwrap(),
+        .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     )
     .execute(ShellCommandContext {
       args,
@@ -430,8 +427,7 @@ impl ShellCommand for NodeModulesFileRunCommand {
     let executable_command = deno_task_shell::ExecutableCommand::new(
       "deno".to_string(),
       std::env::current_exe()
-        .and_then(|p| p.canonicalize())
-        .unwrap(),
+        .unwrap_or_else(|_| PathBuf::from("${PREFIX}/bin/deno")),
     );
     // set this environment variable so that the launched process knows the npm command name
     context.state.apply_env_var(
