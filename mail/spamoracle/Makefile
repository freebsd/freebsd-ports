# New ports collection makefile for:	SpamOracle
# Date created:				Mon Sep 9 18:31:45 UTC 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamoracle
PORTVERSION=	1.2
CATEGORIES=	mail
MASTER_SITES=	http://cristal.inria.fr/~xleroy/software/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	procmail spam filter written in ML using Bayesian classification

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_REINPLACE=	yes
USE_SIZE=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's|^(CPP=)gcc[[:space:]]+-E|\1${CPP}|' \
		${WRKSRC}/Makefile

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
