# New ports collection makefile for:	ocaml cryptokit
# Date created:		Thu Jan  9 03:04:06 BRST 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cryptokit
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A variety of cryptographic primitives for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

USE_REINPLACE=	yes
USE_SIZE=	yes

ALL_TARGET=	all allopt

.ifndef(NOPORTDOCS)
ALL_TARGET+=	doc
.endif

post-configure:
# CFLAGS,PREFIX safeness
	@${REINPLACE_CMD} -E -e \
		's|^(INSTALLDIR).*$$|\1=${PREFIX}/lib/ocaml|; \
		s|^CFLAGS=|CFLAGS\+=|; \
		s|(^CFLAGS.*)-O|\1|' \
		${WRKSRC}/Makefile

pre-install:
# in pre-install to make sure we're using the correct user:group
# combo
	@${REINPLACE_CMD} -E -e \
		's|cp |${INSTALL_DATA} |' \
		${WRKSRC}/Makefile
# create installation dir
	@${MKDIR} ${PREFIX}/lib/ocaml

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
