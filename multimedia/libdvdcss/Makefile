# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdvdcss
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix tar:bzip2

RESTRICTED=	CSS code may violate the DMCA

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doc
DOXYGEN_USES=		gmake

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
