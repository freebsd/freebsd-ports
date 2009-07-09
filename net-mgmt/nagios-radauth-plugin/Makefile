# New ports collection makefile for:	nagios-spamd-plugin
# Date created:				2006-01-18
# Whom:					Andrew Kilpatrick <tiger@whitetigersd.com>
#
# $FreeBSD$

PORTNAME=	nagios-radauth-plugin
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.hick.org/code/skape/radauth/
DISTNAME=	radauth-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin for checking radius server

NAGIOS_PLUGIN_DIR?=	libexec/nagios

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--bindir=${PREFIX}/${NAGIOS_PLUGIN_DIR}

PLIST_FILES=	"@exec ${MKDIR} ${NAGIOS_PLUGIN_DIR}" \
		${NAGIOS_PLUGIN_DIR}/check_radauth
PLIST_DIRS=	${NAGIOS_PLUGIN_DIR}

pre-install:
	@${MKDIR} ${PREFIX}/${NAGIOS_PLUGIN_DIR}

.include <bsd.port.mk>
