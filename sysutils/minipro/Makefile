PORTNAME=	minipro
DISTVERSION=	0.7.4
PORTREVISION=	0
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
GL_TAGNAME=	f124338492a3937dbf02f9c4bc5219892f10481e

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_FILES=	bin/minipro \
		share/man/man1/minipro.1.gz \
		share/minipro/dump-alg-minipro.bash \
		share/minipro/infoic.xml \
		share/minipro/logicic.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
