# New ports collection makefile for:	ocaml-netclient
# Date created:				Thu Aug  4 15:46:59 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	netclient
PORTVERSION=	0.92.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	dsh@vlink.ru
COMMENT=	A HTTP 1.0/1.1, FTP and Telnet client for OCaml

BUILD_DEPENDS=	${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/equeue/equeue.a:${PORTSDIR}/devel/ocaml-equeue
RUN_DEPENDS=	${SA_DIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${SA_DIR}/equeue/equeue.a:${PORTSDIR}/devel/ocaml-equeue

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

ALL_TARGET=	all opt
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

DEPRECATED=	is part of ocaml-net
EXPIRATION_DATE=	2008-04-22
BROKEN=		conflicts with dependency

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
