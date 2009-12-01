# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.0.61
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Computer Algebra System

LIB_DEPENDS=	gsl.14:${PORTSDIR}/math/gsl

USE_AUTOTOOLS=	libtool:22
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

OPTIONS=	X11	"Build with X11 features"			off \
 		GMP	"Use libgmp for arbitrary precision arithmetic" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.if defined(WITH_GMP)
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4
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
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=	X11=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.endif

test:	build
	@cd ${WRKSRC}/manmake && ${GMAKE} wester-1994.ys
	@cd ${WRKSRC}/tests && ${GMAKE} check

.include <bsd.port.post.mk>
