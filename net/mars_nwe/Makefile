# New ports collection makefile for:	mars_nwe
# Date created:		29 Dec 1998
# Whom:			Boris Popov <bp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mars_nwe
PORTVERSION=	0.99.b17
CATEGORIES=	net
MASTER_SITES=	http://www.compu-art.de/download/ \
		ftp://ftp.gwdg.de/pub/linux/misc/ncpfs/mars_nwe/ \
		ftp://ftp.butya.kz/pub/mars_nwe/
DISTNAME=	mars_nwe-0.99.pl17
EXTRACT_SUFX=	.tgz

MAINTAINER=	bp@FreeBSD.org

WRKSRC=		${WRKDIR}/mars_nwe

do-build:
	@(cd ${WRKSRC} && ${MAKE} all)

do-install:
	@(cd ${WRKSRC} && ./mk.li install)
	@${INSTALL_DATA} ${WRKSRC}/examples/nw.ini ${PREFIX}/etc/nwserv.conf.example
	@${ECHO} "You'll need to create a startup file to load MARS_NWE Server when booting."
	@${ECHO}  "Create a nwserv.sh in ${PREFIX}/etc/rc.d directory and modify"
	@${ECHO}  "${PREFIX}/etc/nwserv.conf manually before you loading server."
	@${ECHO} "Kernel should be compiled with IPX support and IPXrouted should be"
	@${ECHO} "started before server."
	@${ECHO}  ""
	@${ECHO} "Please read details in ${WORKDIR}/mars_nwe/doc directory."
	@${ECHO} "Especially README.FREEBSD file."

.include <bsd.port.mk>
