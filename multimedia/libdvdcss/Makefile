# Created by: ijliao
# $FreeBSD$

PORTNAME=	libdvdcss
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption

LICENSE=	GPLv2
LICENSE_FILES=	${WRKSRC}/COPYING

RESTRICTED=	CSS code may violate the DMCA

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix tar:bzip2
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
