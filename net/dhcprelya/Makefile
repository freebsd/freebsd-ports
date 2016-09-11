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

OPTIONS_DEFINE=	DOCS
# The modules use a new system libradius that is not committed yet
#OPTIONS_DEFINE=	RADIUS_PLUGIN
RADIUS_PLUGIN_DESC=		Build radius plugin
RADIUS_PLUGIN_PLIST_FILES=	lib/${PORTNAME}_radius_plugin.so
RADIUS_PLUGIN_MAKE_ON=		-DWITH_RADIUS_PLUGIN

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${STAGEDIR}${PREFIX}#' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
