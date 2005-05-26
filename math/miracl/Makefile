# New ports collection makefile for:	MIRACL
# Date created:		Mon Jan 17 21:38:16 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	miracl
DISTVERSION=	4.85
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.computing.dcu.ie/pub/crypto/
DISTNAME=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Multiprecision Integer and Rational Arithmetic C/C++ Library

USE_ZIP=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	ys

EXTRACT_BEFORE_ARGS=	-j -aa -L

PLIST_FILES=	\
		lib/libmiracl.a

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386"
.endif

post-patch:
# C{C,XX} safeness
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|gcc|${CC}|' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|-O2|${CFLAGS}|' \
		${WRKSRC}/linux

do-build:
	@cd ${WRKSRC} && ${SH} ./linux

do-install:
# lib
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.a \
		${PREFIX}/lib/lib${PORTNAME}.a

.include <bsd.port.post.mk>
