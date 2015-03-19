# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	xsp
PORTVERSION=	3.0.11
CATEGORIES=	www
MASTER_SITES=	GITHUB_LEGACY

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based web server

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono

MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	mono
GH_COMMIT=	4587438
USE_GITHUB=	yes
USE_SQLITE=	3
USES=		gmake mono pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf aclocal
PATHFIX_MAKEFILEIN=Makefile.am

AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I build/m4/shamrock -I build/m4/shave

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-install:
	${MKDIR} ${STAGEDIR}${XSP_DOCROOT}

.include <bsd.port.mk>
