# New ports collection makefile for:	ocaml-netclient
# Date created:				Thu Aug  4 15:46:59 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	netclient
PORTVERSION=	0.91.1
CATEGORIES=	net
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	dsh@vlink.ru
COMMENT=	A HTTP 1.0/1.1, FTP and Telnet client for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/equeue/equeue.a:${PORTSDIR}/devel/ocaml-equeue
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes

ALL_TARGET=	all opt
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OCAML_SITELIBDIR=	${LOCALBASE}/lib/ocaml/site-lib

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
