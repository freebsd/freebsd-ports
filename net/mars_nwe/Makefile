# New ports collection makefile for:	mars_nwe
# Version required:     0.99.pl14
# Date created:		29 Dec 1998
# Whom:			Boris Popov <bp@butya.kz>
#
# $Id: Makefile,v 1.1.1.2 1999/01/27 01:27:42 foxfair Exp $
#

DISTNAME=       mars_nwe-0.99.pl14
PKGNAME=	mars_nwe-0.99b14
CATEGORIES=	net
MASTER_SITES=	http://www.compu-art.de/download/ \
		ftp://ftp.gwdg.de/pub/linux/misc/ncpfs/mars_nwe/ \
		ftp://ftp.butya.kz/pub/mars_nwe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bp@butya.kz

WRKSRC=		${WRKDIR}/mars_nwe

NO_PACKAGE=	ignores cflags

do-build:
	@(cd ${WRKSRC} && ${MAKE} all)

do-install:
	@(cd ${WRKSRC} && ./mk.li install)
	@${ECHO} "You need to create a startup file to load MARS_NWE Server when booting."
	@${ECHO}  "Create a nwserv.sh in ${PREFIX}/etc/rc.d directory and modify"
	@${ECHO}  "${PREFIX}/etc/nwserv.conf manually before you loading server."
	@${ECHO}  "Your kernel _must_ support IPXRoute!"
	@${ECHO}  ""
	@${ECHO}  "After building look details into ${WORKDIR}/mars_nwe/doc directory."
	@${ECHO}  "((Especially this file : README.FREEBSD))"

.include <bsd.port.mk>
