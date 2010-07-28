# New ports collection makefile for:		xsp
# Date created:					20040828
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	xsp
PORTVERSION=	2.6.5
CATEGORIES=	www
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based web server

BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono

MAKE_JOBS_UNSAFE=	yes

USE_SQLITE=	3
USE_BZIP2=	yes
USE_GNOME=	gnometarget gnomehack
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		asp-state.1 dbsessmgr.1 mod-mono-server.1 xsp.1 \
		fastcgi-mono-server.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-su-install:
	${MKDIR} ${XSP_DOCROOT}

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
