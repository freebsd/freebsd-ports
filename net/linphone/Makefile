# New ports collection makefile for:	linphone
# Date created:				30 December 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linphone
PORTVERSION=	0.12.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://simon.morlat.free.fr/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web phone that supports SIP protocol

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm \
		speex.2:${PORTSDIR}/audio/speex \
		osip.9:${PORTSDIR}/net/libosip

USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-ipv6
INSTALLS_SHLIB=	yes

MAN1=		linphone.1 linphonec.1 sipomatic.1

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--enable-gnome_ui=no --with-html-dir=${DOCSDIR}
PLIST_SUB+=	GNOME="@comment " \
		GNOME_PATH="" \
		HTMLDOCSDIR="${DOCSDIR:S,^${PREFIX}/,,}"
.else
USE_X_PREFIX=	yes
USE_GNOME+=	gnomepanel gnomeprefix
DOCSDIR=	${GNOME_HTML_DIR}
PLIST_SUB+=	GNOME="" \
		GNOME_PATH="gnome/" \
		HTMLDOCSDIR="${GNOME_HTML_DIR:S,^${PREFIX}/,,}"
.endif

.include <bsd.port.mk>
