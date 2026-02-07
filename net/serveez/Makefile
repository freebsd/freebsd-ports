PORTNAME=	serveez
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Server framework
WWW=		https://www.gnu.org/software/serveez/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe guile:2.2 libtool pkgconfig tar:lz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-libserveez-install

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

INFO=		serveez

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.in
	@${ECHO_CMD} 'static char created[] = "2021-11-15 13:19 UTC";' \
		> ${WRKSRC}/src/irc-server/timestamp.c

.include <bsd.port.mk>
