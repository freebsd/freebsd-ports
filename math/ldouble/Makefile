# New ports collection makefile for:	ldouble
# Date created:		2004-09-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldouble
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
#	http://www.moshier.net/
MASTER_SITE_SUBDIR=	ahze
DISTFILES=	${LDOUBLE_DISTFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Long double math precision functions

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 sparc64

PLIST_FILES=	lib/libml.a \
		lib/libml.so \
		lib/libml.so.0

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
LDOUBLE_DISTFILE=	ldouble.zip
USE_ZIP=		yes
EXTRA_PATCHES=	${FILESDIR}/i386-makefile-patch
PORTDOCS=	ldoubdoc.html
PLIST_FILES+=	include/mathl.h
.else
LDOUBLE_DISTFILE=	128bit.tgz
EXTRA_PATCHES=	${FILESDIR}/128-makefile-patch
PORTDOCS=	128bdoc.html
.endif

post-patch:
.if ${ARCH}!="sparc64"
	@${REINPLACE_CMD} -e 's|-msoft-quad-float||' \
		${WRKSRC}/${MAKEFILE}
.endif
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; s|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/libml.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libml.so.0 ${PREFIX}/lib
	${LN} -sf libml.so.0 ${PREFIX}/lib/libml.so
.if ${ARCH}=="i386"
	${INSTALL_DATA} ${WRKSRC}/protos.h ${PREFIX}/include/mathl.h
.endif

.include <bsd.port.post.mk>
