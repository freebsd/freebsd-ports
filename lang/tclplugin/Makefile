# New ports collection makefile for:	tclplugin2.0.3
# Version required:	2.0.4-beta
# Date created:		Sat Nov  8 10:46:42 CET 1997
# Whom:			andreas
#
# $Id: Makefile,v 1.4 1997/11/15 23:58:33 andreas Exp $
#

DISTNAME=	tclplugin2.0.4-beta
PKGNAME=	tclplugin-2.0.4b
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/plugin/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=  /nonexistent:${PORTSDIR}/lang/tcl80:build \
		/nonexistent:${PORTSDIR}/x11/tk80:build
RUN_DEPENDS=	netscape:${PORTSDIR}/www/netscape4-communicator

NO_PACKAGE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PORTSDIR}/lang/tcl80/work/tcl8.0/unix \
		--with-tk=${PORTSDIR}/x11/tk80/work/tk8.0/unix \
		--with-mozilla=${PREFIX}/lib/netscape

.include <bsd.port.mk>
