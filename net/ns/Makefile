# New ports collection makefile for: ns-2
# Version required:	2.1b5
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

DISTNAME=	ns-src-2.1b5
PKGNAME=	ns-2.1b5
CATEGORIES=	net
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/vint/

MAINTAINER=	obonilla@fisicc-ufm.edu

BUILD_DEPENDS=	${PREFIX}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl
RUN_DEPENDS=	${PREFIX}/bin/tclsh8.0:${PORTSDIR}/lang/tcl80

MAN1=		ns.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	yes

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ns ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ns.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/ns2
	${INSTALL_DATA} ${WRKSRC}/tcl/ex/*.tcl ${PREFIX}/share/examples/ns2
.include <bsd.port.mk>
