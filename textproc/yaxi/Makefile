# ex:ts=8
# Ports collection makefile for:	yaxi
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yaxi
PORTVERSION=	0.5.2
CATEGORIES=	textproc
MASTER_SITES=	http://mattam.ath.cx/progs/yaxi/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another X* Implementation for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ulex \
		${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/camomile
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ulex \
		${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/camomile

OCAML_SITELIBDIR=	${LOCALBASE}/lib/ocaml/site-lib
USE_GMAKE=	yes

PLIST_FILES=	bin/yaxsltproc

post-install:
	@${ECHO_CMD} "@unexec ocamlfind remove yaxi 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
