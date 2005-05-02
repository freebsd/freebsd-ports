# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.0.57
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LIB_DEPENDS=	gsl.7:${PORTSDIR}/math/gsl

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_GMP)
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=	--with-numlib=gmp
PLIST_SUB+=	GMP="" NOGMP="@comment "
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-numlib=native
PLIST_SUB+=	GMP="@comment " NOGMP=""
.endif

.if defined(WITH_X11)
USE_GL=		yes
CONFIGURE_ARGS+=--with-x
PLIST_SUB+=	X11=""
CPPFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.endif

test:	build
	@cd ${WRKSRC}/manmake && ${GMAKE} wester-1994.ys
	@cd ${WRKSRC}/tests && ${GMAKE} check

.include <bsd.port.post.mk>
