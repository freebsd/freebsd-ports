# New ports collection makefile for:	tclplugin2.0.3
# Date created:		Sat Nov  8 10:46:42 CET 1997
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	tclplugin
PORTVERSION=	2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/plugin/
DISTNAME=	tclplug20-src

MAINTAINER=	ports@FreeBSD.org

BROKEN_ELF=	yes

BUILD_DEPENDS=	netscape:${PORTSDIR}/www/netscape4-communicator
RUN_DEPENDS=	netscape:${PORTSDIR}/www/netscape4-communicator

WRKSRC=		${WRKDIR}/tclplugin2.0/plugin2.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${WRKDIR}/tclplugin2.0/tcl8.0/unix \
		--with-tk=${WRKDIR}/tclplugin2.0/tk8.0/unix \
		--with-mozilla=${PREFIX}/lib/netscape

pre-configure:
	( cd ${WRKDIR}/tclplugin2.0/tcl8.0/unix; ./configure --enable-shared )
	( cd ${WRKDIR}/tclplugin2.0/tk8.0/unix; ./configure --enable-shared )

.include <bsd.port.mk>
