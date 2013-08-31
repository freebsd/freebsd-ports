# Created by: Helko Glathe <glathe.helko@googlemail.com>
# $FreeBSD$

PORTNAME=	clamz
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	glathe.helko@googlemail.com
COMMENT=	Command-line program to download MP3 files from Amazon's music store

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2 \
		gcrypt:${PORTSDIR}/security/libgcrypt

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
USES=		pkgconfig

MAN1=		${PORTNAME}.1

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
