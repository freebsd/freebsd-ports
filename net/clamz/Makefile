# New ports collection makefile for: clamz
# Date created:		2009-06-08
# Whom:			Helko Glathe <glathe.helko@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	clamz
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	glathe.helko@googlemail.com
COMMENT=	Command-line program to download MP3 files from Amazon's music store

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2 \
		gcrypt.17:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

post-configure:
	@${REINPLACE_CMD} \
		-e 's|^\(compile.*\)|\1 -I${LOCALBASE}/include|' \
		-e 's|^\(LIBS\ =\)|\1 ${LOCALBASE}/lib/libexpat.so|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
