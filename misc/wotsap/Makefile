# Created by: ijliao
# $FreeBSD$

PORTNAME=	wotsap
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~jc/wotsap/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Web of trust statistics and pathfinder

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow6>0:graphics/py-pillow6@${PY_FLAVOR}

USES=		python:2.7,run shebangfix
NO_BUILD=	yes
SHEBANG_FILES=	wotsap pks2wot

PLIST_FILES=	bin/pks2wot bin/wotsap
PORTSCOUT=	ignore:1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pks2wot ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wotsap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
