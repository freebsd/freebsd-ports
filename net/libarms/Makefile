# Created by: shigeru@iij.ad.jp
# $FreeBSD$

PORTNAME=	libarms
PORTVERSION=	5.01
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	https://dev.smf.jp/dl/ \
		http://dev.smf.jp/dl/

MAINTAINER=	shigeru@iij.ad.jp
COMMENT=	SMFv2/ARMS client library for C

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		gmake libtool ssl
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct x509_store_ctx_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct x509_store_ctx_st'
.endif

post-configure:
	@${REINPLACE_CMD} 's|$${datarootdir}/doc/$${PACKAGE_TARNAME}|${DOCSDIR}|' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
