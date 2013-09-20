# Created by: RicardoSSP <ricardo.katz@gmail.com>
# $FreeBSD$

PORTNAME=	osbf-lua
PORTVERSION=	2.0.4
CATEGORIES=	mail
MASTER_SITES=	http://luaforge.net/frs/download.php/2094/

MAINTAINER=	ricardo.katz@gmail.com
COMMENT=	This tool is used as classifier for mails, primarily as Anti Spam

USE_GMAKE=	YES
USE_LDCONFIG=	YES
USE_LUA=	5.1+
ALL_TARGET=
INSTALL_TARGET=	install

OPTIONS_DEFINE=		SPAMFILTER_PLUGIN
OPTIONS_DEFAULT=	SPAMFILTER_PLUGIN
SPAMFILTER_PLUGIN_DESC=		OSBF Spamfilter Plugin

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPAMFILTER_PLUGIN}
INSTALL_TARGET+=	install_spamfilter
PLIST_SUB+=		SPAMFILTER=""
.else
PLIST_SUB+=		SPAMFILTER="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/^CC/s/=/?=/' ${WRKSRC}/config

.include <bsd.port.mk>
