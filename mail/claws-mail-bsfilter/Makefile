# New ports collection makefile for:	claws-mail-bsfilter
# Date created:		27 November 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsfilter
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	bsfilter_plugin-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	bsfilter plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.7.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XORG=	x11
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
