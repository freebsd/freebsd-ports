# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsstool
DISTVERSION=	1.0.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	www
MASTER_SITES=	BERLIOS

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Read, parse, merge and write RSS and Atom feeds

USES=		iconv gmake
USE_GNOME=	libxml2
BUILD_WRKSRC=	${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
HAS_CONFIGURE=	yes

post-patch:
	@cd ${BUILD_WRKSRC}/&&${REINPLACE_CMD} -e 's|gcc|${CC}|' Makefile

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} "*html images" ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/contrib/&&${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
