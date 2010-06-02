module Test_RcConf =
	let conf = "# /etc/rc.conf

hostname=\"host.domain\"
defaultrouter=\"4.3.2.1\"
ipv4_addrs_em0=\"4.3.2.2/24\"

foo_enable=\"YES\"
foo_flags=\"-a --foobar\"
bar_enable=\"NO\"
bar_flags=\"\"
"

	test RcConf.lns get conf =
		{ "#comment" = "/etc/rc.conf" }
		{}
		{ "hostname" = "host.domain" }
		{ "defaultrouter" = "4.3.2.1" }
		{ "ipv4_addrs_em0" = "4.3.2.2/24" }
		{}
		{ "foo_enable" = "YES" }
		{ "foo_flags" = "-a --foobar" }
		{ "bar_enable" = "NO" }
		{ "bar_flags" = "" }
