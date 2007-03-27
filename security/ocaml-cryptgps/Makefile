# New ports collection makefile for:	ocaml-cryptgps
# Date created:		2006-08-01
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	cryptgps
PORTVERSION=	0.2.1
CATEGORIES=	security
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Symmetric cryptographic algorithms package for OCaml

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

ALL_TARGET=	all opt
MASTERPORT=	${PORTSDIR}/devel/ocaml-camlidl

.if !defined(NOPORTDOCS)
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
.endif

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
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
