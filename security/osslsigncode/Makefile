PORTNAME=	osslsigncode
DISTVERSION=	2.10
CATEGORIES=	security devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	OpenSSL-based signcode utility
WWW=		https://github.com/mtrojnar/osslsigncode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake pkgconfig python ssl
USE_GITHUB=	yes
GH_ACCOUNT=	mtrojnar

PLIST_FILES=	bin/osslsigncode \
		share/bash-completion/completions/osslsigncode.bash

OPTIONS_DEFINE=		CURL GSF
OPTIONS_DEFAULT=	CURL GSF

GSF_DESC?=		GSF support (enables signing of e.g. MSI files)

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
GSF_LIB_DEPENDS=	libgsf-1.so:devel/libgsf
GSF_CONFIGURE_WITH=	gsf

post-patch:
	${TOUCH} ${WRKSRC}/stamp-h1 ${WRKSRC}/config.h.in

.include <bsd.port.mk>
