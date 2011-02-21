# New ports collection makefile for:	pidgin-privacy-please
# Date created:				01 Sep 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pidgin-privacy-please
PORTVERSION=	0.6.4
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A privacy plugin for the pidgin instant messenger

LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	${PREFIX}/lib/pidgin

LICENSE=	GPLv2

.include <bsd.port.mk>
