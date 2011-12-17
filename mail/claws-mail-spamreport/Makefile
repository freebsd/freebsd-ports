# New ports collection makefile for:	claws-mail-spamreport
# Date created:		06 April 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spamreport
PORTVERSION=	0.3.15
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	spam_report-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	SpamReport plugin for claws-mail

LICENSE=	GPLv3

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.8.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XORG=	x11
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
