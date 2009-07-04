# New ports collection makefile for:	sylpheed-claws-vcalendar
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	vcalendar
PORTVERSION=	2.0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	c0rn@o2.pl
COMMENT=	vCalendar plugin for claws-mail

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.2:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf:262
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
