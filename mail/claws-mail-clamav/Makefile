# New ports collection makefile for:	claws-mail-clamav
# Date created:		26 November 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Clamav plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.3.1:${PORTSDIR}/mail/claws-mail
LIB_DEPENDS=	clamav.3:${PORTSDIR}/security/clamav

USE_GMAKE=	yes
USE_XORG=	x11
USE_AUTOTOOLS=	autoconf:261

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

PLIST_FILES=	lib/claws-mail/plugins/clamav.a \
		lib/claws-mail/plugins/clamav.la \
		lib/claws-mail/plugins/clamav.so

.include <bsd.port.mk>
