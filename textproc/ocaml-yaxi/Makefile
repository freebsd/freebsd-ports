# ex:ts=8
# Ports collection makefile for:	yaxi
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yaxi
PORTVERSION=	0.5.3
CATEGORIES=	textproc
MASTER_SITES=	http://mattam.org/soft/yaxi/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another X* Implementation for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/ocaml-camomile
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${OCAML_SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net \
		${OCAML_SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/ocaml-camomile

OCAML_SITELIBDIR=	${LOCALBASE}/lib/ocaml/site-lib
USE_GMAKE=	yes

PLIST_FILES=	bin/yaxsltproc

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.pre.mk>

pre-install:
	${MKDIR} ${PREFIX}/lib/ocaml/site-lib

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${PORTNAME} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
