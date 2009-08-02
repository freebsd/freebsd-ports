# New ports collection makefile for:	hdf-szip
# Date created:		3 March 2005
# Whom:			glewis
#
# $FreeBSD$
#

PORTNAME=	szip
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	science archivers
MASTER_SITES=	ftp://ftp.hdfgroup.org/lib-external/szip/2.1/src/:src \
		http://www.hdfgroup.org/doc_resource/SZIP/:doc
PKGNAMEPREFIX=	hdf-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${DOCFILE}:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Lossless compression library for scientific data

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCFILE=	Release_notes_2_0.pdf
LDFLAGS+=	-lm
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DOCFILE} ${DOCSDIR}
.endif

.include <bsd.port.mk>
