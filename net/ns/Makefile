# New ports collection makefile for: ns-2
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	2.27
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTNAME=	ns-src-2.27

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The UCB/LBNL Network Simulator Version 2

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84

MAN1=		ns.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/ns-2.27

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4

ALL_TARGET=

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Does not compile on alpha 4.x"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/ns2
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${PREFIX}/share/examples/ns2

.include <bsd.port.post.mk>
