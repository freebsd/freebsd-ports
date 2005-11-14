# New ports collection makefile for: idnits
# Date Created:		9 July 2004
# Whom:			fenner@FreeBSD.Org
#
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	1.82
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Looks for problems in internet draft formatting

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
