# New ports collection makefile for:   synce-hal
# Date created:                14 May 2008
# Whom:                        Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$

PORTNAME=	hal
PORTVERSION=	0.13.1
PORTEPOCH=	1
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/0.13
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
USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE} --with-hal-addon-dir=${PREFIX}/libexec --disable-bluetooth-support

PLIST_FILES=	libexec/hal-dccm \
		libexec/synce-serial-chat \
		libexec/hal-synce-rndis \
		libexec/hal-synce-serial \
		share/synce-hal/dhclient.conf \
		share/hal/fdi/policy/20thirdparty/10-synce.fdi

PLIST_DIRS=	share/synce-hal
.include <bsd.port.mk>
