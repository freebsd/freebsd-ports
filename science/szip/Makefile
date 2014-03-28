# Created by: glewis
# $FreeBSD$

PORTNAME=	szip
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	science archivers
MASTER_SITES=	ftp://ftp.hdfgroup.org/lib-external/szip/2.1/src/:src \
		http://www.hdfgroup.org/doc_resource/SZIP/:doc
PKGNAMEPREFIX=	hdf-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTDOCS}:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lossless compression library for scientific data

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-lm
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"
PLIST_FILES=	include/ricehdf.h include/szip_adpt.h include/szlib.h \
		lib/libsz.a lib/libsz.la lib/libsz.so lib/libsz.so.2
PORTDOCS=	Release_notes_2_0.pdf

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
