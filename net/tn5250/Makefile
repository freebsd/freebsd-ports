PORTNAME=	tn5250
DISTVERSION=	0.17.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	5250 Telnet protocol and Terminal
WWW=		https://github.com/tn5250/tn5250

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool ncurses ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-os-dir=no --with-ssl=${OPENSSLBASE}

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS =/s|linux||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-data-local|:|g' ${WRKSRC}/freebsd/Makefile.in

.include <bsd.port.mk>
