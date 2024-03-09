PORTNAME=	tinyxml2
PORTVERSION=	10.0.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small C++ XML Parser
WWW=		https://leethomason.github.io/tinyxml2/ \
		https://github.com/leethomason/tinyxml2

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang cpe dos2unix meson pathfix

MESON_ARGS=	--default-library=both \
		-Ddebug=false \
		-Dtests=true
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	leethomason
USE_GITHUB=	yes

CPE_VENDOR=	tinyxml2_project

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} resources ${STAGEDIR}${EXAMPLESDIR}/

do-test:
	cd ${WRKSRC}/ && _build/xmltest

.include <bsd.port.mk>
