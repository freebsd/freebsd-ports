# ex:ts=8
# Ports collection makefile for:	wotsap
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wotsap
PORTVERSION=	0.6
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~jc/wotsap/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web of trust statistics and pathfinder

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pks2wot bin/wotsap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pks2wot ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wotsap ${PREFIX}/bin

.include <bsd.port.mk>
