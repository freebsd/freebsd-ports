# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${LINPHONE_PORTNAME}
PORTVERSION=	${LINPHONE_PORTVERSION}
PORTREVISION=	${LINPHONE_PORTREVISION}
PORTEPOCH=	${LINPHONE_PORTEPOCH}
CATEGORIES=	net
MASTER_SITES=	${LINPHONE_MASTER_SITES}
PKGNAMESUFFIX=	-base

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm \
		speex.3:${PORTSDIR}/audio/speex \
		osip.9:${PORTSDIR}/net/libosip

USE_GNOME=	glib20 gnomehack gnometarget intlhack pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-ipv6 --enable-gnome_ui=no \
		--with-speex=${LOCALBASE} --with-html-dir=${DOCSDIR}
INSTALLS_SHLIB=	yes

MAN1=		linphonec.1 sipomatic.1

CFLAGS+=	-DPACKAGE_LOCALE_DIR='\"${PREFIX}/share/locale\"' \
		-DPACKAGE_DATA_DIR='\"${PREFIX}/share\"' \
		-DPACKAGE_SOUND_DIR='\"${DATADIR}/sounds\"'

.include "Makefile.common"
.include <bsd.port.pre.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/share/C/linphonec.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/share/C/sipomatic.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/linphone.pc ${PREFIX}/libdata/pkgconfig
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/share/*.wav ${DATADIR}/sounds
	@${MKDIR} ${DATADIR}/sounds/rings
	${INSTALL_DATA} ${WRKSRC}/share/rings/*.wav ${DATADIR}/sounds/rings
	@${MKDIR} ${PREFIX}/share/linphonec
	${INSTALL_DATA} ${WRKSRC}/share/linphonec ${PREFIX}/share/linphonec

.include <bsd.port.post.mk>
