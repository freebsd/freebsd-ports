# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${LINPHONE_PORTNAME}
PORTVERSION=	${LINPHONE_PORTVERSION}
PORTREVISION=	2
PORTREVISION=	${LINPHONE_PORTREVISION}
PORTEPOCH=	${LINPHONE_PORTEPOCH}
CATEGORIES=	net gnome
MASTER_SITES=	${LINPHONE_MASTER_SITES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	linphone.1:${PORTSDIR}/net/linphone-base

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-ipv6 --disable-gtk-doc \
		--with-speex=${LOCALBASE} --with-osip=${LOCALBASE}
MAKE_ENV=	SUBDIRS="pixmaps gnome"

MAN1=		linphone.1

CFLAGS+=	-DPACKAGE_LOCALE_DIR='\"${LOCALBASE}/share/locale\"' \
		-DPACKAGE_DATA_DIR='\"${PREFIX}/share/gnome\"' \
		-DPACKAGE_SOUND_DIR='\"${LOCALBASE}/share/linphone/sounds\"'

.include "${.CURDIR}/../../net/linphone-base/Makefile.common"
.include <bsd.port.pre.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/share/C/linphone.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/linphone.desktop \
		${PREFIX}/share/gnome/applications

.include <bsd.port.post.mk>
