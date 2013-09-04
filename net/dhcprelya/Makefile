# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	dhcprelya
PORTVERSION=	4.7
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Lightweight DHCP relay agent. Yandex edition

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	sem-hub
GH_COMMIT=	6df4e97

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
