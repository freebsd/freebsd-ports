PORTNAME=	snowballstemmer
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Snowball stemmer library for C
WWW=		https://snowballstem.org/

LICENSE=	BSD3CLAUSE

USES=		gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

MAKEFILE=	GNUmakefile

USE_GITHUB=	yes
GH_ACCOUNT=	snowballstem
GH_PROJECT=	snowball

PLIST_FILES=	bin/stemwords \
		include/libstemmer.h \
		lib/libstemmer.so \
		lib/libstemmer.so.3 \
		lib/libstemmer.so.3.0.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stemwords ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/libstemmer.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libstemmer.so.3.0.1 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstemmer.so.3.0.1 \
		${STAGEDIR}${PREFIX}/lib/libstemmer.so.3
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstemmer.so.3.0.1 \
		${STAGEDIR}${PREFIX}/lib/libstemmer.so

.include <bsd.port.mk>
