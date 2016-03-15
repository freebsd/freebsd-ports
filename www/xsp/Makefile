# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	xsp
PORTVERSION=	3.0.11
CATEGORIES=	www

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based web server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	mono
USE_GITHUB=	yes
USES=		gmake mono pathfix pkgconfig sqlite
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
USE_AUTOTOOLS=	automake autoconf aclocal
PATHFIX_MAKEFILEIN=Makefile.am

AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I build/m4/shamrock -I build/m4/shave

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-install:
	${MKDIR} ${STAGEDIR}${XSP_DOCROOT}

.include <bsd.port.mk>
