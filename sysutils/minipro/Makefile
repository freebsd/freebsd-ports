PORTNAME=	minipro
DISTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	bofh@freebsd.org
COMMENT=	CLI for MiniPRO TL866xx chip programmers
WWW=		https://gitlab.com/DavidGriffith/minipro

LICENSE=	GPLv3

BUILD_DEPENDS=	gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	DavidGriffith
GL_PROJECT=	${PORTNAME}
GL_TAGNAME=	e8244313c2558b41a390824e1f847f449ebd7fce

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_FILES=	bin/minipro \
		man/man1/minipro.1.gz \
		share/minipro/infoic.xml \
		share/minipro/logicic.xml

post-install:
	@${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/minipro.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
