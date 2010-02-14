# New ports collection makefile for:   cheetah
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cheetah
PORTVERSION=	0.10
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ based light-weight web browser

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFLICTS=	py??-cheetah-[0-9]*

# XXX: when removing this port, don't forget to also remove needless
# CONFLICTS from devel/py-cheetah
BROKEN=		crashes on loading any webpage
DEPRECATED=	broken, unmaintained, development ceased in 2001
EXPIRATION_DATE=2010-03-14

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
