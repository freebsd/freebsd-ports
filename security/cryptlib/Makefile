# New ports collection makefile for:   cryptlib
# Date created:        17 Jun, 2003
# Whom:                Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		cryptlib
PORTVERSION=		3.1
PORTREVISION=	1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.franken.de/pub/crypt/cryptlib/
DISTNAME=		cl31
EXTRACT_SUFX=		.zip

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A powerful security programming toolkit

ONLY_FOR_ARCHS=		i386

USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes
USE_GMAKE=		yes
MAKEFILE=		makefile
ALL_TARGET=		default FreeBSD shared

INSTALLS_SHLIB=		yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/endian ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libcl.a ${WRKSRC}/libcl.so.3.1.0 \
		${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libcl.so.3.1.0 ${PREFIX}/lib/libcl.so
	${INSTALL_DATA} ${WRKSRC}/cryptlib.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cryptlib
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cryptlib
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/endian
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
