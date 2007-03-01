# New ports collection makefile for: idnits
# Date Created:		9 July 2004
# Whom:			fenner@FreeBSD.Org
#
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	2.03.9
CATEGORIES=	textproc
MASTER_SITES=	http://tools.ietf.org/tools/idnits/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Looks for problems in internet draft formatting

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
