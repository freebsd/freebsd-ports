# New ports collection makefile for:	mod_smooth_streaming
# Date created:				May 25, 2010
# Whom:					Marcus Hermansson <bmhermansson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mod_smooth_streaming
PORTVERSION=	1.0.8
CATEGORIES=	www
MASTER_SITES=	http://smoothstreaming.code-shop.com/download/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	apache_${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	apache22

MAINTAINER=	bmhermansson@gmail.com
COMMENT=	Apache smooth streaming module

RESTRICTED=	no-commercial-use

USE_APACHE=	22+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	APACHEMODDIR=${APACHEMODDIR}

post-install:
		${LOCALBASE}/sbin/apxs -e -a -n smooth_streaming ${LOCALBASE}/${APACHEMODDIR}/${PORTNAME}.so
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
