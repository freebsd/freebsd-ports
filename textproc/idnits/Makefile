# New ports collection makefile for: idnits
# Date Created:		9 July 2004
# Whom:			fenner@FreeBSD.Org
#
# $FreeBSD$

PORTNAME=	idnits
PORTVERSION=	1.63
CATEGORIES=	textproc
MASTER_SITES=	http://ietf.levkowetz.com/tools/idnits/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Looks for problems in internet draft formatting

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/idnits

.include <bsd.port.mk>
