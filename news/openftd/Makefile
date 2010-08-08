#
# Ports collection makefile for:	news/openftd
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2007-05-02
#
# $FreeBSD$
#

PORTNAME=	openftd
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	news
MASTER_SITES=	http://www.icheb.nl/mirrors/openftd/

MAINTAINER=	edwin@mavetju.org
COMMENT=	FreeBSD version of the Fill Threads Database program

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		notify.1:${PORTSDIR}/devel/libnotify \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		sexy.2:${PORTSDIR}/x11-toolkits/libsexy

BROKEN=		does not configure

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GECKO=	libxul

USE_GNOME=	glib20 libxml2 gtk20 libgnome gtkhtml3 libxslt

CONFIGURE_ARGS=	--with-libcurl-libraries=${LOCALBASE}/lib \
		--with-pcre_libraries=${LOCALBASE}/lib

.include <bsd.port.mk>
