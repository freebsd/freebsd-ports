# New ports collection makefile for: unison
# Date created:		4 October 2000
# Whom:			Dan Pelleg <dpelleg+unison@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	unison
PORTVERSION=	2.9.20
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/beta-test/${DIST_SUBDIR}/
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_DOCS}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	src.tar.gz

MAINTAINER=	daniel+unison@pelleg.org
COMMENT=	A user-level file synchronization tool

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
PATCH_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
MAKE_ARGS=	UISTYLE=text CFLAGS=""

.if !defined(NOPORTDOCS)
DOCS=		BUGS.txt NEWS README
EXTRA_DOCS=	unison-manual.dvi unison-manual.html \
		unison-manual.pdf unison-manual.ps
.endif

pre-patch:
	@if [ `ocamlc -version | ${SED} -e s/\\\.//g -e s/\\\+.*//` -gt 307 ] ; then \
		if ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/ocaml-external-patch-ab ; then \
			${TRUE} ; \
		else \
			${ECHO_MSG} ">> Patch ocaml-external-patch-ab failed to apply cleanly." ; \
			${FALSE} ; \
		fi; \
	fi

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/unison
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${EXTRA_DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
