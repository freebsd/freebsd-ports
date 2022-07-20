PORTNAME=	libdvdcss
DISTVERSION=	1.4.3
CATEGORIES=	multimedia
MASTER_SITES=	https://download.videolan.org/pub/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption

LICENSE=	GPLv2 DMCA
LICENSE_COMB=	multi
LICENSE_NAME_DMCA=	DMCA
LICENSE_TEXT_DMCA=	CSS code may violate the DMCA
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_PERMS_DMCA=	auto-accept

USES=		libtool pathfix tar:bzip2

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
