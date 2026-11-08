PORTNAME=	libdvdcss
DISTVERSION=	1.6.0
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/${DISTVERSION}/ \
		https://download.videolan.org/pub/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Portable abstraction library for DVD decryption
WWW=		https://www.videolan.org/developers/libdvdcss.html \
		https://code.videolan.org/videolan/libdvdcss

LICENSE=	GPLv2 DMCA
LICENSE_COMB=	multi
LICENSE_NAME_DMCA=	DMCA
LICENSE_TEXT_DMCA=	CSS code may violate the DMCA
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_PERMS_DMCA=	auto-accept

USES=		meson tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=shared

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_MESON_TRUE=	enable_docs

.include <bsd.port.mk>
