# $FreeBSD$

PORTNAME=	intel-undervolt
DISTVERSION=	1.5-7
DISTVERSIONSUFFIX=	-g66cfb65
CATEGORIES=	sysutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Intel CPU undervolting tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kitsunyan

MAKE_ARGS=	CC="${CC}" SYSCONFDIR="${PREFIX}/etc"

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample"

post-patch:
	${REINPLACE_CMD} "s|/bin/bash|${LOCALBASE}/bin/bash|g" ${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
