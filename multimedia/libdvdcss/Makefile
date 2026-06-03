PORTNAME=	libdvdcss
DISTVERSION=	1.5.0
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption
WWW=		https://www.videolan.org/developers/libdvdcss.html

LICENSE=	GPLv2 DMCA
LICENSE_COMB=	multi
LICENSE_NAME_DMCA=	DMCA
LICENSE_TEXT_DMCA=	CSS code may violate the DMCA
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_PERMS_DMCA=	auto-accept

USES=		meson pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org/
GL_ACCOUNT=	videolan

PORTDOCS=	AUTHORS COPYING NEWS README.md

MESON_ARGS=	-Ddefault_library=shared

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_ON=	-Denable_docs=true
DOXYGEN_MESON_OFF=	-Denable_docs=false

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
