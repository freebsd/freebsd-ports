# Created by: RicardoSSP <ricardo.katz@gmail.com>
# $FreeBSD$

PORTNAME=	osbf-lua
PORTVERSION=	2.0.4
CATEGORIES=	mail
MASTER_SITES=	http://luaforge.net/frs/download.php/2094/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email classifier, primarily for anti-spam

LICENSE=	GPLv2

USES=		gmake lua:51
USE_LDCONFIG=	YES
ALL_TARGET=
INSTALL_TARGET=	install

OPTIONS_DEFINE=		SPAMFILTER_PLUGIN
OPTIONS_DEFAULT=	SPAMFILTER_PLUGIN
SPAMFILTER_PLUGIN_DESC=		OSBF Spamfilter Plugin

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
