# Ports collection makefile for:   ekg
# Date created:        24 March 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$

PORTNAME=		ekg
PORTVERSION=		1.7
PORTREVISION=		1
PORTEPOCH=		2
CATEGORIES=		polish net-im
MASTER_SITES=		http://ekg.chmurka.net/

MAINTAINER=		bartlomiej@syryjczyk.name
COMMENT=		Text-mode Gadu-Gadu client

LIB_DEPENDS=		execinfo.1:${PORTSDIR}/devel/libexecinfo \
			gadu.3:${PORTSDIR}/polish/libgadu

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		gnomehack pkgconfig
CONFIGURE_ARGS+=	--disable-shared \
			--disable-static \
			--enable-dynamic \
			--disable-libgadu-openssl \
			--without-libungif \
			--without-libjpeg

CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lexecinfo ${PTHREAD_LIBS}"

OPTIONS=	ASPELL "Build with ASPELL support" off \
		OPENSSL "Build with OPENSSL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell.16:${PORTSDIR}/polish/aspell
CONFIGURE_ARGS+=	--enable-aspell
.endif

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-openssl
.endif

USE_LDCONFIG=	yes

MAN1=		ekg.1
MANLANG=	"" pl
MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ekg

.include <bsd.port.post.mk>
