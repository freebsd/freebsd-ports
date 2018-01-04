# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhcprelya
PORTVERSION=	6.1
CATEGORIES=	net

MAINTAINER=	sem@semmy.ru
COMMENT=	Lightweight DHCP relay agent. Yandex edition

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	sem-hub
GH_TAGNAME=	a4d10c4

USE_RC_SUBR=	dhcprelya

PORTDOCS=	README ChangeLog

PLIST_FILES=	sbin/${PORTNAME} lib/${PORTNAME}_log_plugin.so \
		lib/${PORTNAME}_option82_plugin.so \
		lib/${PORTNAME}_radius_plugin.so

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
