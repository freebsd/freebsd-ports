# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.2.x/ \
		ftp://ftp.uk.xmms.org/xmms/1.2.x/ \
		ftp://ftp.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.ca.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.md.us.xmms.org/xmms/1.2.x/ \
		ftp://ftp.nl.xmms.org/xmms/1.2.x/ \
		ftp://ftp.de.xmms.org/xmms/1.2.x/

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12 \
		xml.5:${PORTSDIR}/textproc/libxml \
		mikmod.2:${PORTSDIR}/audio/libmikmod \
		esd.2:${PORTSDIR}/audio/esound

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_GNOME)
CONFIGURE_ARGS=	--with-gnome
.else
CONFIGURE_ARGS= --without-gnome
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITH_GNOME)
pre-extract:
	@${ECHO} "You can add support for GNOME by defining WITH_GNOME"
.endif

.if defined(WITH_GNOME)
post-install:
	@${ECHO} bin/gnomexmms >> ${TMPPLIST}
	@${ECHO} etc/CORBA/servers/gnomexmms.gnorba >> ${TMPPLIST}
	@${ECHO} share/gnome/applets/Multimedia/gnomexmms.desktop >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
