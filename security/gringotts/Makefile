# New ports collection makefile for:	gringotts
# Date created:				02 July 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gringotts
PORTVERSION=	0.5.9
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/Gringotts/current/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	mcrypt.7:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--disable-env-check
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

WANT_GNOME=	yes
.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else

post-patch:
		@${PATCH} < ${FILESDIR}/gnomeless-Makefile.in \
			${WRKSRC}/Makefile.in >/dev/null 2>&1
.endif

.include <bsd.port.post.mk>
