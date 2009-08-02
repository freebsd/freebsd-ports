# New ports collection makefile for:		mod_mono
# Date created:					20040828
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.39 2007/12/13 19:35:47 killfill Exp $
#

PORTNAME=	mod_mono
PORTVERSION=	2.4.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Apache module for serving ASP.NET applications

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr
BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		xsp:${PORTSDIR}/www/xsp

USE_APACHE=	2.0+
USE_BZIP2=	yes
USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--man=${PREFIX}/man

MAN8=		mod_mono.8

.include <bsd.port.pre.mk>
.if ${APACHE_VERSION} == 13
MOD_MONOCONFDIR=${APACHEETCDIR}
.else
MOD_MONOCONFDIR=${APACHEETCDIR}/Includes
.endif

PLIST_SUB+= MOD_MONOCONFDIR=${MOD_MONOCONFDIR}

post-patch:
	@${REINPLACE_CMD} 's|%%MOD_MONOCONFDIR%%|${PREFIX}/${MOD_MONOCONFDIR}|g' \
		${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
