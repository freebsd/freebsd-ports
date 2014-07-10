# Created by: snb@threerings.net
# $FreeBSD$

PORTNAME=	osslsigncode
PORTVERSION=	1.7
CATEGORIES=	security devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	OpenSSL-based signcode utility

PLIST_FILES=	bin/osslsigncode

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=		CURL GSF
OPTIONS_DEFAULT=	CURL GSF
CURL_CONFIGURE_WITH=	curl
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
GSF_DESC?=		GSF support (enables signing of e.g. MSI files)
GSF_CONFIGURE_WITH=	gsf
GSF_LIB_DEPENDS=	libgsf-1.so:${PORTSDIR}/devel/libgsf

.include <bsd.port.mk>
