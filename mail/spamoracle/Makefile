# New ports collection makefile for:	SpamOracle
# Date created:				Mon Sep 9 18:31:45 UTC 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamoracle
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://cristal.inria.fr/~xleroy/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	procmail spam filter written in ML using Bayesian classification

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_REINPLACE=	yes

MAN1=	spamoracle.1
MAN5=	spamoracle.conf.5

PLIST_FILES=	bin/spamoracle	
.ifndef(NOPORTDOCS)
PORTDOCS=	Changes README
.endif

do-configure:
	@${REINPLACE_CMD} -E -e 's|^(CPP=)gcc[[:space:]]+-E|\1${CPP}|' \
		-e 's|^(MANDIR=).*$$|\1${MANPREFIX}/man|' \
		-e 's|^(BINDIR=).*$$|\1${PREFIX}/bin|' \
		${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
