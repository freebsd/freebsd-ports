# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.1.b9
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTNAME=	ns-src-2.1b9

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.3:${PORTSDIR}/lang/tcl83

MAN1=		ns.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/ns-2.1b9

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.3 --with-tk-ver=8.3

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/ns2
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${PREFIX}/share/examples/ns2
.include <bsd.port.mk>
