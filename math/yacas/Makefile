# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.0.54
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://yacas.sourceforge.net/backups/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LIB_DEPENDS=	gsl.4:${PORTSDIR}/math/gsl

USE_PERL5_BUILD=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_GMP)
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif
CONFIGURE_ARGS+=	--with-numlib=gmp
.else
CONFIGURE_ARGS+=	--with-numlib=native
.endif

.if defined(WITH_X)
USE_XLIB=	yes
USE_MESA=	yes
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=	WITH_X=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	WITH_X="@comment "
.endif

.include <bsd.port.post.mk>
