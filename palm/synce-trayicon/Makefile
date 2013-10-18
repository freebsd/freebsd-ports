# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	synce-trayicon
PORTVERSION=	0.14
PORTREVISION=	5
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE-GNOME/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME system tray app for monitoring connected WinCE based devices

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LIB_DEPENDS=	rra.0:${PORTSDIR}/palm/synce-librra \
		gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		unshield.0:${PORTSDIR}/archivers/unshield \
		orange.0:${PORTSDIR}/archivers/liborange \
		notify.4:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd-synce:${PORTSDIR}/palm/synce-gvfs \
		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon


BROKEN=		fails to build
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=        pathfix gettext
USE_GNOME=	gnomeprefix libgnomeui desktopfileutils
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	${PORTNAME}.schemas
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
SUB_FILES=	pkg-message

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	@if [ -z "`${GREP} libsynce ${LOCALBASE}/libdata/pkgconfig/liborange.pc`" ]; then \
	    ${ECHO_MSG} ; \
	    ${ECHO_MSG} "${PKGNAME} requires archivers/liborange built with LIBSYNCE option ON" ; \
	    ${ECHO_MSG} ; \
	    ${FALSE}; \
	fi
	@if [ -z "`${GREP} libunshield ${LOCALBASE}/libdata/pkgconfig/liborange.pc`" ]; then \
	    ${ECHO_MSG} ; \
	    ${ECHO_MSG} "${PKGNAME} requires archivers/liborange built with LIBUNSHIELD option ON" ; \
	    ${ECHO_MSG} ; \
	    ${FALSE}; \
	fi

post-install:
	@-update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
