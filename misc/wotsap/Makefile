# ex:ts=8
# Ports collection makefile for:	wotsap
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wotsap
PORTVERSION=	0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.lysator.liu.se/~jc/wotsap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web of trust statistics and pathfinder

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

PLIST_FILES=	bin/wotsap
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wotsap.py ${PREFIX}/bin/wotsap

.include <bsd.port.mk>
