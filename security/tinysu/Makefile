# Created by: zakj@nox.cx
# $FreeBSD$

PORTNAME=	tinysu
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://peff.net/tinysu/

MAINTAINER= ports@FreeBSD.org
COMMENT=	Featureless replacement for su and sudo

PLIST_FILES=	bin/tinysu

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_STAGE=	yes
post-extract:
	@${ECHO_CMD} ${PREFIX} >${WRKSRC}/conf-home

.include <bsd.port.mk>
