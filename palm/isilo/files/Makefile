# Use BSD_INSTALL_SCRIPT so that it doesn't try to strip the binary, 
# which breaks Linux apps.
#
# $FreeBSD$

install: 
	${BSD_INSTALL_SCRIPT} iSilo386 ${PREFIX}/bin
	/usr/bin/brandelf -t Linux ${PREFIX}/bin/iSilo386
	@${BSD_INSTALL_MAN} iSilo386.1 ${PREFIX}/man/man1

