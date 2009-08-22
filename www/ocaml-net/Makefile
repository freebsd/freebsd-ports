# New ports collection makefile for:   ocaml-net
# Date created:        01 March 2003
# Whom:                Stephane Legrand <stephane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	net
PORTVERSION=	2.2.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/ocaml${PORTNAME}/ocaml${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml${PORTNAME}-${PORTVERSION}

MAINTAINER=	manfred.lotz@yahoo.de
COMMENT=	OCaml modules for Internet applications

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

CONFLICTS=	ocaml-equeue-2* ocaml-netclient-0*

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
HAS_CONFIGURE=	yes

ALL_TARGET=	all opt

PLIST_FILES=	bin/netplex-admin \
		bin/ocamlrpcgen

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PKGNAMEPREFIX}${PORTNAME}
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
PORTEXAMPLES=	*
.endif

OCAML_PKGDIRS=	netsys netshm equeue shell netstring rpc-generator \
		rpc pop smtp netclient netcgi1 netcgi2 cgi netplex \
		netcgi2-plex

post-install:

.for pkg in ${OCAML_PKGDIRS}
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${pkg} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)

	@${MKDIR} ${EXAMPLESDIR}/
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
