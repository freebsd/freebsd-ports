--- README.md.orig	2026-11-07 09:51:58 UTC
+++ README.md
@@ -29,7 +29,7 @@ These options can be used when starting the `postfix_e
 | `--postfix.showq_path`    | Path at which Postfix places its showq socket       | `/var/spool/postfix/public/showq` |
 | `--postfix.showq_port`    | TCP port at which showq is listening                | `10025`                           |
 | `--postfix.showq_network` | Network protocol to use to connect to showq         | `"unix"`                          |
-| `--postfix.logfile_path` | Path where Postfix writes log entries                | `/var/log/mail.log`               |
+| `--postfix.logfile_path` | Path where Postfix writes log entries                | `/var/log/maillog`                |
 | `--postfix.logfile_must_exist` | Fail if the log file doesn't exist.            | `true`                            |
 | `--postfix.logfile_poll` | Poll for file changes instead of using inotify.      | `false`                           |
 | `--postfix.logfile_debug` | Enable debug logging for the log file.              | `false`                           |
