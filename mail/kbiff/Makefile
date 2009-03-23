# New ports collection makefile for:	kbiff
# Date created:		So  14 Jun 1998 13:09:18 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	kbiff
PORTVERSION=	3.8
PORTREVISION=	3
CATEGORIES=	mail kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail notification utility for KDE with nice features

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-fast-perl
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
MAN1=		kbiff.1

OPTIONS=	SSL	"SSL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
