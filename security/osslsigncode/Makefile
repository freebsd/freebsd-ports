# Created by: snb@threerings.net
# $FreeBSD$

PORTNAME=	osslsigncode
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSSL-based signcode utility

PLIST_FILES=	bin/osslsigncode

USES=		pkgconfig ssl
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CURL GSF
OPTIONS_DEFAULT=	CURL GSF
CURL_CONFIGURE_WITH=	curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
GSF_DESC?=		GSF support (enables signing of e.g. MSI files)
GSF_CONFIGURE_WITH=	gsf
GSF_LIB_DEPENDS=	libgsf-1.so:devel/libgsf

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	variable has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
BROKEN_FreeBSD_13=	variable has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
.endif

post-patch:
	${TOUCH} ${WRKSRC}/stamp-h1 ${WRKSRC}/config.h.in

.include <bsd.port.post.mk>
