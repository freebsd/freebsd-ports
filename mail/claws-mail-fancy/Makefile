# New ports collection makefile for:	claws-mail-fancy
# Date created:		2009-07-06
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	fancy
PORTVERSION=	0.9.10
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	Webkit based HTML renderer plugin for claws-mail

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		webkit:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	claws-mail>=3.7.5:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.5:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_ICONV=	yes
USE_GNOME=	gtk20

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

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
