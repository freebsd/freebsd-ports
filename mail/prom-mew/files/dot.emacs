;;;
;;; Prom-Mew
;;;
(autoload 'prom-mew "prom-mew" "mew for using procmail" t)
(setq proc-log-list (list "~/Mail/from-log"))
	;; logfile name that procmail output (LOGFILE in ~/.procmail)
(setq proc-keep-log "~/Mail/listlog")	;; logfile name for preserve
(setq proc-lock-file "~/Mail/.lock")	;; lockfile name (LOCKFILE in ~/.procmail)
