# New ports collection makefile for:	hdf-szip
# Date created:		3 March 2005
# Whom:			glewis
#
# $FreeBSD$
#

PORTNAME=	szip
PORTVERSION=	2.0
CATEGORIES=	science archivers
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/szip/${PORTVERSION}/src/:src \
		http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/:doc
PKGNAMEPREFIX=	hdf-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${DOCFILE}:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Lossless compression library for scientific data

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
DOCFILE=	Release_notes_2_0.pdf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DOCFILE} ${DOCSDIR}
.endif

.include <bsd.port.mk>
