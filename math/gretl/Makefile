# ex:ts=8
# Ports collection makefile for:	gretl
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gretl
PORTVERSION=	1.1.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnu Regression, Econometrics and Time-series Library

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack \
		gmp.6:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gnometarget gtksourceview libxml2
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake
INSTALLS_SHLIB=	yes

MAN1=	gretl.1 gretl-config.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"math/lapack appears to be broken on alpha"
.endif

.if ${HAVE_GNOME:Mlibgnomeui}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	libgnomeprintui libgnomeui
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng"|libpng12"|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
