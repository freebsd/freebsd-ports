# New ports collection makefile for:   synce-hal
# Date created:                14 May 2008
# Whom:                        Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$

PORTNAME=	hal
PORTVERSION=	0.2
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce
PKGNAMEPREFIX=	synce-
DISTNAME=	synce-hal-${PORTVERSION}

MAINTAINER=	webmaster@kibab.com
COMMENT=	SynCE part: manages devices' connections

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce  \
		hal.1:${PORTSDIR}/sysutils/hal \
		gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}

PLIST_FILES=	libexec/hal-dccm \
		libexec/synce-serial-chat \
		libexec/hal-synce-rndis \
		libexec/hal-synce-serial \
		share/hal/fdi/policy/20thirdparty/10-synce.fdi

.include <bsd.port.mk>
