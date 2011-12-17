# New ports collection makefile for:	sylpheed-claws-vcalendar
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	vcalendar
PORTVERSION=	2.0.12
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	vCalendar plugin for claws-mail

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf
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
