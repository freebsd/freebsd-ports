# Ports collection makefile for:   ekg
# Date created:        24 March 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$

PORTNAME=		ekg
PORTVERSION=		1.7.r2
PORTEPOCH=		2
CATEGORIES=		polish net-im
MASTER_SITES=		http://ekg.chmurka.net/
DISTNAME=		${PORTNAME}-1.7rc2

MAINTAINER=		alex@bsdguru.org
COMMENT=		Text-mode Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/libgadu

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		gnomehack pkgconfig
CONFIGURE_ARGS+=	--disable-shared \
			--disable-static \
			--enable-dynamic

CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

OPTIONS=	ASPELL "Build with ASPELL support" off
		
.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell.16:${PORTSDIR}/polish/aspell
CONFIGURE_ARGS+=	--enable-aspell
.endif

USE_LDCONFIG=	yes

MAN1=		ekg.1
MANLANG=	"" pl
MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ekg

.include <bsd.port.post.mk>
