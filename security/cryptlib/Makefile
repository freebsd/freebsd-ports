# Created by: Foxfair Hu <foxfair@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cryptlib
PORTVERSION=		3.4.1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.franken.de/pub/crypt/cryptlib/
DISTNAME=		cl${PORTVERSION:S/.//g}

MAINTAINER=		ale@FreeBSD.org
COMMENT=		Powerful security programming toolkit

ONLY_FOR_ARCHS=		i386 amd64

OPTIONS_DEFINE=		DOCS

USES=		zip
EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes
MAKEFILE=		makefile
ALL_TARGET=		default FreeBSD shared
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=		include/cryptlib.h \
			lib/libcl.a lib/libcl.so \
			lib/libcl.so.3 lib/libcl.so.${PORTVERSION}

PORTDOCS=		README

post-patch:
	@${REINPLACE_CMD} -e 's/%%CFLAGS%%/${CFLAGS}/' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%%PTHREAD_CFLAGS%%/${PTHREAD_CFLAGS}/' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's/%%PTHREAD_LIBS%%/${PTHREAD_LIBS}/' ${WRKSRC}/tools/getlibs.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcl.a ${WRKSRC}/libcl.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf libcl.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcl.so.3
	${LN} -sf libcl.so.3 ${STAGEDIR}${PREFIX}/lib/libcl.so
	${INSTALL_DATA} ${WRKSRC}/cryptlib.h ${STAGEDIR}${PREFIX}/include

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
