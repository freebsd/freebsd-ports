PORTNAME=	dfc
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1.20251014
CATEGORIES=	sysutils

MAINTAINER=	mcy@lm7.fr
COMMENT=	Display file system space usage using graph and colors
WWW=		https://github.com/rolinh/dfc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	rolinh
# This commit fixes build with CMake 4
GH_TAGNAME=	b14e3162963d5edefe9ab293f97fd21fba08c496

CMAKE_ARGS+=	-DDFC_DOC_PATH=${DOCSDIR} \
		-DMAN_PATH=${PREFIX}/share/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_ON=	-DNLS_ENABLED=true
NLS_CMAKE_OFF=	-DNLS_ENABLED=false

.include <bsd.port.mk>
