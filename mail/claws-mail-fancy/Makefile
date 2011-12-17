# New ports collection makefile for:	claws-mail-fancy
# Date created:		2009-07-06
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	fancy
PORTVERSION=	0.9.15
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Webkit based HTML renderer plugin for claws-mail

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		soup-gnome:${PORTSDIR}/devel/libsoup-gnome \
		webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_ICONV=	yes
USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
