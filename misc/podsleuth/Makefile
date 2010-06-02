# New ports collection makefile for:	podsleuth
# Date created:		2008-07-09
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	podsleuth
PORTVERSION=	0.6.7
CATEGORIES=	misc
MASTER_SITES=	http://download.banshee-project.org/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A tool to discover detailed model information about an iPod

LIB_DEPENDS=	sgutils2.2:${PORTSDIR}/sysutils/sg3_utils \
		hal.1:${PORTSDIR}/sysutils/hal
BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus
RUN_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus

CONFIGURE_ARGS+=--with-hal-callouts-dir=${PREFIX}/libexec
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig

.include <bsd.port.mk>
