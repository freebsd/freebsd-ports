# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.1.b5
CATEGORIES=	net
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/vint/
DISTNAME=	ns-src-2.1b5

MAINTAINER=	obonilla@fisicc-ufm.edu

BUILD_DEPENDS=	${PREFIX}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
RUN_DEPENDS=	${PREFIX}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

MAN1=		ns.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/ns-2.1b5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.2 --with-tk-ver=8.2

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/ns2
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${PREFIX}/share/examples/ns2
.include <bsd.port.mk>
