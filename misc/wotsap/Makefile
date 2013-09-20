# Created by: ijliao
# $FreeBSD$

PORTNAME=	wotsap
PORTVERSION=	0.7
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~jc/wotsap/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Web of trust statistics and pathfinder

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

USE_PYTHON_RUN=	-2.7
NO_BUILD=	yes

PLIST_FILES=	bin/pks2wot bin/wotsap
PORTSCOUT=	ignore:1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pks2wot ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wotsap ${PREFIX}/bin

.include <bsd.port.mk>
