# New ports collection makefile for:	claws-mail-tnef
# Date created:		26 November 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tnef
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	tnef_parse-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	TNEF parser plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail
LIB_DEPENDS=	ytnef.0:${PORTSDIR}/devel/libytnef

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:261
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
