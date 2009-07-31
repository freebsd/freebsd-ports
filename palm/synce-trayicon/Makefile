# New ports collection makefile for:   synce-trayicon
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-trayicon
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GNOME system tray app for monitoring connected WinCE based devices

LIB_DEPENDS=	rra.0:${PORTSDIR}/palm/synce-librra \
		gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		unshield.0:${PORTSDIR}/archivers/unshield \
		orange.0:${PORTSDIR}/archivers/liborange \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd-synce:${PORTSDIR}/palm/synce-gvfs \
		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	${PORTNAME}.schemas
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

MAN1=		${PORTNAME}.1

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
