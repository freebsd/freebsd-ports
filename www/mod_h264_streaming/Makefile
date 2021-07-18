# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>

PORTNAME=	mod_h264_streaming
PORTVERSION=	2.2.7
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://h264.code-shop.com/download/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	apache_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Apache H264 streaming module

# Converted from RESTRICTED
LICENSE=	h264
LICENSE_NAME=	h264
LICENSE_TEXT=	No commercial use
LICENSE_PERMS=	auto-accept

USES=		apache:2.2+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	SED=${SED}

.include <bsd.port.mk>
