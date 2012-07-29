# New ports collection makefile for:    osbf-lua
# Date created:         2009-01-14
# Whom:                 RicardoSSP <ricardo.katz@gmail.com>
#
# $FreeBSD$
#

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

OPTIONS=	SPAMFILTER_PLUGIN "OSBF Spamfilter Plugin" on

.include <bsd.port.pre.mk>

.if defined(WITH_SPAMFILTER_PLUGIN)
INSTALL_TARGET+=	install_spamfilter
PLIST_SUB+=		SPAMFILTER=""
.else
PLIST_SUB+=		SPAMFILTER="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/^CC/s/=/?=/' ${WRKSRC}/config

.include <bsd.port.post.mk>
