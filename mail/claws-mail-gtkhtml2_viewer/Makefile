# New ports collection makefile for:	sylpheed-claws-gtkhtml2_viewer
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml2_viewer
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed-claws.net/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-

MAINTAINER=	c0rn@o2.pl
COMMENT=	HTML renderer plugin for sylpheed-claws

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	sylpheed-claws>=2.5:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.5:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259
USE_GNOME=	libgtkhtml
USE_ICONV=	yes
USE_GETTEXT=	yes

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
	--with-libintl-prefix=${LOCALBASE}

PLIST_FILES=	lib/sylpheed-claws/plugins/gtkhtml2_viewer.a \
	lib/sylpheed-claws/plugins/gtkhtml2_viewer.la \
	lib/sylpheed-claws/plugins/gtkhtml2_viewer.so \
	share/locale/de/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/fi/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/sk/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/sr/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/es/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/fr/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/pl/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/pt_BR/LC_MESSAGES/gtkhtml2_viewer.mo

.include <bsd.port.mk>
