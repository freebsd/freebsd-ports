# New ports collection makefile for:	ocaml jabbr
# Date created:		Thu Jan  9 05:59:43 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jabbr
PORTVERSION=	0.0.${DATE_VERSION}
CATEGORIES=	net-im
MASTER_SITES=	http://mikelin.mit.edu/xmpp/jabbr/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	jabbr

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	XML Messaging and Presence Protocol a.k.a. Jabber for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/cryptokit.cma:${PORTSDIR}/security/ocaml-cryptokit \
		${LOCALBASE}/lib/ocaml/yaxpo.cma:${PORTSDIR}/textproc/ocaml-yaxpo

# depend when building as well
BUILD_DEPENDS+=	${RUN_DEPENDS}

DATE_VERSION=	20021124

post-configure:
# PREFIX safeness
	@${REINPLACE_CMD} -E -e \
		's|^(INSTALLDIR).*$$|\1=${PREFIX}/lib/ocaml|' \
		${WRKSRC}/Makefile

post-build:
.ifndef(NOPORTDOCS)
	@cd ${WRKSRC} && ${MAKE} doc
.endif

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
