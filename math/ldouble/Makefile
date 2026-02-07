PORTNAME=	ldouble
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	LOCAL/ahze
#	http://www.moshier.net/
DISTFILES=	${LDOUBLE_DISTFILE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Long double math precision functions
WWW=		http://www.moshier.net/

BUILD_DEPENDS=	as:devel/binutils

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

PLIST_FILES=	lib/libml.a \
		lib/libml.so \
		lib/libml.so.0

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
LDOUBLE_DISTFILE=	ldouble.zip
EXTRA_PATCHES=	${FILESDIR}/i386-makefile-patch
PORTDOCS=	ldoubdoc.html
PLIST_FILES+=	include/mathl.h
.else
LDOUBLE_DISTFILE=	128bit.tgz
EXTRA_PATCHES=	${FILESDIR}/128-makefile-patch
PORTDOCS=	128bdoc.html
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-msoft-quad-float||' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|; s|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libml.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libml.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libml.so.0 ${STAGEDIR}${PREFIX}/lib/libml.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libml.so
.if ${ARCH}=="i386"
	${INSTALL_DATA} ${WRKSRC}/protos.h ${STAGEDIR}${PREFIX}/include/mathl.h
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
