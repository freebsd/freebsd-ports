# New ports collection makefile for:	MIRACL
# Date created:		Mon Jan 17 21:38:16 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	miracl
PORTVERSION=	5.23
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.computing.dcu.ie/pub/crypto/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprecision Integer and Rational Arithmetic C/C++ Library

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

EXTRACT_BEFORE_ARGS=	-j -aa -L

PLIST_FILES=	lib/libmiracl.a \
		include/miracl.h include/mirdef.h

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not build on !i386
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
# headers
	@${INSTALL_DATA} ${WRKSRC}/miracl.h \
		${PREFIX}/include/miracl.h
	@${INSTALL_DATA} ${WRKSRC}/mirdef.h \
		${PREFIX}/include/mirdef.h

.include <bsd.port.post.mk>
