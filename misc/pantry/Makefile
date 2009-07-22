# New ports collection makefile for:	pantry
# Date created:		21 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pantry
PORTVERSION=	0.${DISTVERSION}
DISTVERSION=	31
CATEGORIES=	misc
MASTER_SITES=	http://www.smileystation.com/pantry/downloads/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line nutrition analysis program

RUN_DEPENDS=	py*-bsddb>=2:${PORTSDIR}/databases/py-bsddb

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1=	${PORTNAME}.1
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

post-extract:
	@${MV} ${WRKSRC}/docs/${PORTNAME}.1 ${WRKSRC}/
	@${MV} ${WRKSRC}/CHANGELOG ${WRKSRC}/docs/

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@cd ${WRKSRC}/docs/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@cd ${WRKSRC}/examples/&&${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif
.ifndef NOPORTDATA
	@${INSTALL} -d ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/master ${DATADIR}/
.endif

test:
	${PREFIX}/bin/pantry --ignore-case --name apple --print names ${DATADIR}/master

.include <bsd.port.mk>
