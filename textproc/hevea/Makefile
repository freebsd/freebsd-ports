# New ports collection makefile for:	hevea
# Date created:		November 28 1999
# Whom:			Stephen Montgomery-Smith <stephen@math.missouri.edu>
#
# $FreeBSD$
#

PORTNAME=		hevea
PORTVERSION=		1.06
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/para/hevea/
DISTFILES=		${PORTNAME}-${PORTVERSION}.tar.gz \
			${PORTNAME}-${PORTVERSION}-manual-dvi.tar.gz \
			${PORTNAME}-${PORTVERSION}-manual.pdf \
			${PORTNAME}-${PORTVERSION}-manual.ps.gz \
			${PORTNAME}-${PORTVERSION}-manual.tar.gz
EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=		stephen@math.missouri.edu

BUILD_DEPENDS=		ocamlc:${PORTSDIR}/lang/ocaml

PLIST_SUB=		HEVEAVERSION=${PORTVERSION}

TEX_DIR=		${PREFIX}/share/texmf/tex/latex
TEXHASH=		${PREFIX}/bin/texhash

post-install:
	strip ${PREFIX}/bin/hevea
	strip ${PREFIX}/bin/hacha
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.pdf ${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.ps.gz ${PREFIX}/share/doc/hevea
	(cd ${PREFIX}/share/doc/hevea; ${TAR} xvfz ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.tar.gz)
	(cd ${PREFIX}/share/doc/hevea; ${TAR} xvfz ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual-dvi.tar.gz)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/hevea
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
