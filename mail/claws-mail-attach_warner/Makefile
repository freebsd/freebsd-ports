# New ports collection makefile for:	claws-mail-attach_warner
# Date created:	2 March 2007
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	attach_warner
PORTVERSION=	0.2.20
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	attachwarner-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Not attached file warning plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.8:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.8:${PORTSDIR}/mail/claws-mail

LICENSE=	GPLv3

USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-iconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
