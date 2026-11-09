PORTNAME=	snowballstemmer
DISTVERSION=	3.2.0
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
		lib/libstemmer.so.${DISTVERSION:R:R} \
		lib/libstemmer.so.${DISTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stemwords ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/libstemmer.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libstemmer.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstemmer.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libstemmer.so.${DISTVERSION:R:R}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libstemmer.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libstemmer.so

.include <bsd.port.mk>
