module RcConf =
	autoload xfm
	
	let comment  = Util.comment
	let empty    = Util.empty
	let eol      = Util.eol
	let eq       = Util.del_str "="
	let dquot    = Util.del_str "\""
	let char     = /[^\n]/
	let var_name = /[A-Za-z0-9_]+/
	
	let value = dquot . store char* . dquot
	let kv_pair = [ key var_name . eq . value . eol ]

	let lns = (comment | empty | kv_pair)*

	let filter = incl "/etc/rc.conf"
		. incl "/boot/loader.conf"
		. Util.stdexcl

	let xfm = transform lns filter
