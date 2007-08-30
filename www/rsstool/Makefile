# New ports collection makefile for:	rsstool
# Date created:		11 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rsstool
DISTVERSION=	1.0.0rc3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	www
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read, parse, merge and write RSS and Atom feeds

USE_ICONV=	yes
USE_GNOME=	libxml2
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
HAS_CONFIGURE=	yes

post-patch:
	@cd ${BUILD_WRKSRC}/&&${REINPLACE_CMD} -e 's|gcc|${CC}|' Makefile

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "*html images" ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@cd ${WRKSRC}/contrib/&&${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
