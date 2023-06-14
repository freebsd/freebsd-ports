PORTNAME=	savvycan
PORTVERSION=	213
PORTEPOCH=	2
CATEGORIES=	net

MAINTAINER=	leres@FreeBSD.org
COMMENT=	CAN bus reverse engineering and capture tool
WWW=		https://www.savvycan.com/

LICENSE=	MIT

USES=		compiler:c++11-lang gmake python:build qmake qt:5
USE_QT=		core gui help network opengl printsupport serialbus serialport \
		websockets-qml widgets buildtools:build

USE_GITHUB=	yes
GH_TUPLE=	collin80:SavvyCAN:V${PORTVERSION}
NO_MTREE=	yes
PLIST_FILES=	bin/savvycan

PORTSCOUT=	skipv:continuous

OPTIONS_DEFINE+=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/SavvyCAN ${STAGEDIR}${PREFIX}/bin/savvycan
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
