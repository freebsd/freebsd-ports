# New ports collection makefile for:   ocaml-net
# Date created:        01 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	net
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocamlnet
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephane@freebsd.org
COMMENT=	OCaml modules for Internet applications

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes

HAS_CONFIGURE=	yes
# seems required to build www/ocaml-wdialog:
CONFIGURE_ARGS+=	-enable-compatcgi

ALL_TARGET=	all opt

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	*
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/cgi -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/cgi" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove cgi 2>/dev/null || true" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/netstring -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/netstring" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove netstring 2>/dev/null || true" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/../examples/ ${EXAMPLESDIR}
	@${CHMOD} -R +r ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
