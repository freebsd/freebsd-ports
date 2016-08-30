# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcprelya
PORTVERSION=	4.9
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight DHCP relay agent. Yandex edition

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	sem-hub
GH_TAGNAME=	d42e83b

USE_RC_SUBR=	dhcprelya

PORTDOCS=	README

PLIST_FILES=	sbin/${PORTNAME} lib/${PORTNAME}_log_plugin.so \
		lib/${PORTNAME}_option82_plugin.so

# The modules use a new system libradius that is not committed yet
#OPTIONS_DEFINE=	RADIUS_PLUGIN
RADIUS_PLUGIN_PLUGIN_DESC=	build radius plugin

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRADIUS_PLUGIN}
PLIST_FILES+=	lib/${PORTNAME}_radius_plugin.so
MAKE_ARGS=	-DWITH_RADIUS_PLUGIN
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${STAGEDIR}/${PREFIX}#' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.mk>
