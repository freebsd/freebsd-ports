# Created by: glewis
# $FreeBSD$

PORTNAME=	szip
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	science archivers
MASTER_SITES=	http://www.hdfgroup.org/ftp/lib-external/${PORTNAME}/${PORTVERSION}/src/:src \
		http://www.hdfgroup.org/doc_resource/SZIP/:doc \
		LOCAL/sunpoet:src,doc
PKGNAMEPREFIX=	hdf-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTDOCS}:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lossless compression library for scientific data

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LIBS+=		-lm
USE_LDCONFIG=	yes
USES=		libtool

PORTDOCS=	Release_notes_2_0.pdf

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
