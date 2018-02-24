# Created by: Jacek Pelka <jacek@combit.com.pl>
# $FreeBSD$

PORTNAME=	ekg
DISTVERSION=	1.8rc2
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	polish net-im
MASTER_SITES=	http://ekg.chmurka.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-mode Gadu-Gadu client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libgadu.so:polish/libgadu

USES=		gmake localbase ncurses pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--without-libungif \
		--without-libjpeg \
		--disable-ui-gtk

LDFLAGS+=	-lncurses -lexecinfo -pthread

OPTIONS_DEFINE=		ASPELL OPENSSL
OPTIONS_DEFAULT=	OPENSSL

ASPELL_CONFIGURE_ON=	--enable-aspell
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_RUN_DEPENDS=	pl-aspell>0:polish/aspell

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_OFF=	--without-openssl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ekg

.include <bsd.port.mk>
