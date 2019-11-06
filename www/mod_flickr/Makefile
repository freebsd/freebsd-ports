# Created by: vshankar
# $FreeBSD$

PORTNAME=	mod_flickr
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.vshank.com/modcode/

MAINTAINER=	venkyshankar@yahoo.com
COMMENT=	Apache module for Flickr API access

BROKEN=		unfetchable

LIB_DEPENDS=	libcurl.so:ftp/curl

XTRA_FLAGS=	-lcurl

AP_INC=		${LOCALBASE}/include
AP_LIB=		${LOCALBASE}/lib

.if defined(WITH_DEBUG)
XTRA_FLAGS+=	-DDEBUG
.endif

AP_EXTRAS=	${XTRA_FLAGS}
USE_LDCONFIG=	yes

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/mod_flickr.c

.include <bsd.port.mk>
