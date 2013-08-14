# Created by: ijliao
# $FreeBSD$

PORTNAME=	serveez
PORTVERSION=	0.2.1
CATEGORIES=	net devel
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server framework

LICENSE=	GPLv3 # (or later)

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-libserveez-install
USE_LDCONFIG=	yes

MAN1=		serveez.1 serveez-config.1
INFO=		serveez

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's| -release .*||' ${WRKSRC}/src/libserveez/Makefile.in
	@${REINPLACE_CMD} -e \
		'/date -r/s|^|#|' ${WRKSRC}/src/irc-server/Makefile.in
	@${ECHO_CMD} 'static char created[] = "2013-03-27 07:52 UTC";' \
		> ${WRKSRC}/src/irc-server/timestamp.c

.include <bsd.port.mk>
