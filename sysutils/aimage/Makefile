# Created by: Chris Calvey <chris@securityforensics.co.uk>
# $FreeBSD$

PORTNAME=	aimage
PORTVERSION=	3.2.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://digitalcorpora.org/downloads/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Advanced Disk Imager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libafflib.so:sysutils/afflib

USES=		gmake readline ssl
GNU_CONFIGURE=	yes
# Pretend ssl3_new exists for LibreSSL.  It's never really used but
# configure checks for it.
CONFIGURE_ARGS=	ac_cv_lib_ssl_ssl3_new=yes

PLIST_FILES=	bin/aimage

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	error: field has incomplete type 'EVP_MD_CTX' (aka 'evp_md_ctx_st')
BROKEN_FreeBSD_13=	error: field has incomplete type 'EVP_MD_CTX' (aka 'evp_md_ctx_st')
.endif

.include <bsd.port.post.mk>
