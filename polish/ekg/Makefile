# Created by: Jacek Pelka <jacek@combit.com.pl>
# $FreeBSD$

PORTNAME=	ekg
DISTVERSION=	1.8rc1
PORTEPOCH=	2
CATEGORIES=	polish net-im
MASTER_SITES=	http://ekg.chmurka.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu client

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		gadu.3:${PORTSDIR}/polish/libgadu

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
CONFIGURE_ARGS+=--disable-shared \
		--disable-static \
		--enable-dynamic \
		--disable-libgadu-openssl \
		--without-libungif \
		--without-libjpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	ASPELL OPENSSL
OPTIONS_DEFAULT=	OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=		aspell.16:${PORTSDIR}/polish/aspell
CONFIGURE_ARGS+=	--enable-aspell
.endif

.if empty(PORT_OPTIONS:MOPENSSL)
CONFIGURE_ARGS+=	--without-openssl
.endif

USE_LDCONFIG=	yes

MAN1=		ekg.1
MANLANG=	"" pl
MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ekg

.include <bsd.port.mk>
