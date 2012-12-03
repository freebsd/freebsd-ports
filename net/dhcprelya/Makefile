# New ports collection makefile for:	dhcprelya
# Date created:				17 December 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dhcprelya
PORTVERSION=	4.5
CATEGORIES=	net
MASTER_SITES=	http://sem.semmy.ru/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Lightweight DHCP relay agent. Yandex edition

LICENSE=	BSD

USE_RC_SUBR=	dhcprelya

PORTDOCS=	README

PLIST_FILES=	sbin/${PORTNAME} lib/${PORTNAME}_log_plugin.so \
		lib/${PORTNAME}_option82_plugin.so

# The modules use a new system libradius that is not committed yet
#OPTIONS_DEFINE=	RADIUS_PLUGIN
RADIUS_PLUGIN_PLUGIN_DESC=	build radius plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRADIUS_PLUGIN}
PLIST_FILES+=	lib/${PORTNAME}_radius_plugin.so
LIB_DEPENDS=	freeradius-client.2:${PORTSDIR}/net/freeradius-client
MAKE_ARGS=	-DWITH_RADIUS_PLUGIN
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
