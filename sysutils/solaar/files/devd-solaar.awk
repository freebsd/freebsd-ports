/^ATTRS/ {
	split($0, attrs, /(==|")/)
	vendor = attrs[3]
	product = attrs[6]
	if (devices[vendor] == "") {
		devices[vendor] = sprintf("0x%s", product);
	} else {
		devices[vendor] = sprintf("%s|0x%s", devices[vendor], product);
	}
}

END {
	printf \
"# Allows non-root users to have raw access to Logitech Unifying USB\n" \
"# Receiver devices.\n\n"

	for (vendor in devices) {
		if (devices[vendor] ~ /\|/) {
			products = sprintf("(%s)", devices[vendor])
		} else {
			products = devices[vendor]
		}
		printf \
"notify 100 {\n" \
"	match \"system\" \"USB\";\n" \
"	match \"subsystem\" \"DEVICE\";\n" \
"	match \"type\" \"ATTACH\";\n" \
"	match \"vendor\" \"0x%s\";\n" \
"	match \"product\" \"%s\";\n" \
"# Please uncomment the line below and change the group name to suit\n" \
"# your own needs.\n" \
"#	action \"chgrp solaar /dev/$cdev && chmod 660 /dev/$cdev\";\n" \
"};\n\n", vendor, products
	}
}
