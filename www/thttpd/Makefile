# New ports collection makefile for: 	thttpd
# Version required:	thttpd-2.16
# Date created:		24 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	thttpd-2.16
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

NO_PACKAGE=     "Group needs to be created for users to have their own web dirs"

GNU_CONFIGURE=	yes

MAN1=		makeweb.1 htpasswd.1
MAN8=		thttpd.8 redirect.8 ssi.8 syslogtocern.8

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thttpd ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/thttpd.8 ${PREFIX}/man/man8
	@${INSTALL} -d -o root -g wheel -m 0775 ${PREFIX}/www
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/www/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/redirect ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/ssi ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/phf ${PREFIX}/www/cgi-bin/
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/redirect.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/ssi.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/makeweb ${PREFIX}/bin/
	@${INSTALL} -c -m 755 -o root -g wheel ${WRKSRC}/extras/syslogtocern ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/htpasswd ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/extras/makeweb.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/htpasswd.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/syslogtocern.8 ${PREFIX}/man/man8

post-install: message

pre-configure: config-message

post-build: config-message

config-message:
	@${ECHO} "====================================================================="
	@${ECHO} ""
	@${ECHO} "Be sure to take a look at the options in config.h before (re)building"
	@${ECHO} "if you want to tweak the server."
	@${ECHO} ""
	@${ECHO} "====================================================================="

message:
	@${ECHO} "====================================================================="
	@${ECHO} ""
	@${ECHO} "If you want users to be able to create their own web subdirectories"
	@${ECHO} "off of the main web directory, you need to:"
	@${ECHO} ""
	@${ECHO} "a) add a group for www admins"
	@${ECHO} "b) chgrp yourgroup ${PREFIX}/bin/makeweb ${PREFIX}/www"
	@${ECHO} "c) chmod 2755 ${PREFIX}/bin/makeweb"
	@${ECHO} "d) tell them about makeweb(1)"
	@${ECHO} ""
	@${ECHO} "====================================================================="

.include <bsd.port.mk>
