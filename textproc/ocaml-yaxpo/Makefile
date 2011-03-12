# New ports collection makefile for:	ocaml yaxpo
# Date created:		Thu Jan  9 05:25:48 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaxpo
PORTVERSION=	0.0.${DATE_VERSION}
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://compbio.mit.edu/mikelin/yaxpo/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	yaxpo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-validating XML 1.0 + XMLNS processing suite for Objective Caml

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_OCAML=	yes
ALL_TARGET=	yaxpo
MAKE_JOBS_SAFE=	yes

DATE_VERSION=	20050614

.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc

PORTDOCS=	*
.endif

post-configure:
# PREFIX safeness
	@${REINPLACE_CMD} -E -e \
		's|^(INSTALLDIR).*$$|\1=${PREFIX}/lib/ocaml|' \
		${WRKSRC}/Makefile

pre-install:
# in pre-install to make sure we're using the correct user:group
# combo
	@${REINPLACE_CMD} -E -e \
		's|cp -f |${INSTALL_DATA} |' \
		${WRKSRC}/Makefile
# create installation dir
	@${MKDIR} ${PREFIX}/lib/ocaml

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
