# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsstool
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read, parse, merge and write RSS and Atom feeds

LICENSE=	GPLv2+

USES=		iconv gmake
USE_GNOME=	libxml2
BUILD_WRKSRC=	${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e 's|gcc|${CC}|' Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*html images" ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
