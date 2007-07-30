# New ports collection makefile for:	pantry
# Date created:		21 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pantry
PORTVERSION=	0.${DISTVERSION}
DISTVERSION=	11
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Command-line nutrition analysis program

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1=	${PORTNAME}.1
PORTDATA=	master
PYDISTUTILS_PKGVERSION=	${DISTVERSION}

post-extract:
	@${MV} ${WRKSRC}/docs/${PORTNAME}.1 ${WRKSRC}/

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/docs/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/examples/&&${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif
.ifndef NOPORTDATA
	@${INSTALL} -d ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/master ${DATADIR}/
.endif

.include <bsd.port.mk>
