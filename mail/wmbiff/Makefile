# New ports collection makefile for:	wmbiff
# Date created:			19 Nov 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmbiff
PORTVERSION=	0.4.27
PORTREVISION=	11
CATEGORIES=	mail windowmaker afterstep
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	An xbiff-like Window Maker dock app

OPTIONS_DEFINE=	GNUTLS

USE_XORG=	xpm
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		wmbiff.1
MAN5=		wmbiffrc.5
PLIST_FILES=	bin/wmbiff \
		lib/wmbiff/security.debian.rb \
		%%DATADIR%%/sample.wmbiffrc \
		%%DATADIR%%/skins/wmbiff-master-contrast.xpm \
		%%DATADIR%%/skins/wmbiff-master-led.xpm
PLIST_DIRS=	%%DATADIR%%/skins \
		%%DATADIR%% \
		lib/wmbiff

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${LOCALBASE} \
			--with-libgcrypt-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-crypto
.endif

post-install:
	@${ECHO_MSG} "===>   Installing sample.wmbiffrc to ${DATADIR}"
	@${ECHO_MSG} "===>   Modify it to suit your needs and copy to ~/.wmbiffrc"
	@${INSTALL_DATA} -m 644 ${WRKSRC}/wmbiff/sample.wmbiffrc ${DATADIR}

.include <bsd.port.post.mk>
