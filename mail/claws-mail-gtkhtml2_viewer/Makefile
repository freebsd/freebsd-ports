# New ports collection makefile for:	sylpheed-claws-gtkhtml2_viewer
# Date created:	7 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml2_viewer
PORTVERSION=	0.15.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	HTML renderer plugin for claws-mail

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.0.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.0.1:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:261
USE_GNOME=	libgtkhtml
USE_ICONV=	yes
USE_GETTEXT=	yes

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
	--with-libintl-prefix=${LOCALBASE}

PLIST_FILES=	lib/claws-mail/plugins/gtkhtml2_viewer.a \
	lib/claws-mail/plugins/gtkhtml2_viewer.la \
	lib/claws-mail/plugins/gtkhtml2_viewer.so \
	share/locale/de/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/fi/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/it/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/sk/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/sr/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/es/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/fr/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/pl/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/pt_BR/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/hu/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/ca/LC_MESSAGES/gtkhtml2_viewer.mo \
	share/locale/zh_CN/LC_MESSAGES/gtkhtml2_viewer.mo

.include <bsd.port.mk>
