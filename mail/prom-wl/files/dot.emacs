;;;
;;; Prom-WL
;;;
(autoload 'prom-wl "prom-wl" "Prom for Wanderlust" t)
(setq proc-log-list (list "~/Mail/from-log"))
	;; logfile name that procmail output (LOGFILE in ~/.procmailrc)
(setq proc-keep-log "~/Mail/listlog")	;; logfile name for preserve
(setq proc-lock-file "~/Mail/.lock")	;; lockfile name (LOCKFILE in ~/.procmailrc)
