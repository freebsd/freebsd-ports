# Created by: ijliao
# $FreeBSD$

PORTNAME=	wotsap
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~jc/wotsap/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Web of trust statistics and pathfinder

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

USES=		python:2,run
NO_BUILD=	yes

PLIST_FILES=	bin/pks2wot bin/wotsap
PORTSCOUT=	ignore:1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pks2wot ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wotsap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
