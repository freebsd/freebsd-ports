# New ports collection makefile for: nam
# Version required:	1.0a7
# Date created:		26 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

DISTNAME=	nam-src-1.0a7
PKGNAME=	nam-1.0a7
CATEGORIES=	net
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/vint/

MAINTAINER=	obonilla@fisicc-ufm.edu

BUILD_DEPENDS=	${LOCALBASE}/lib/libtclcl.a:${PORTSDIR}/devel/tclcl

MAN1=		nam.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.2 --with-tk-ver=8.2

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/examples/nam
	${INSTALL_DATA} ${WRKSRC}/ex/* ${PREFIX}/share/examples/nam
.include <bsd.port.mk>
