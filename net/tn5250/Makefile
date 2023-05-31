PORTNAME=	tn5250
PORTVERSION=	0.17.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	5250 Telnet protocol and Terminal
WWW=		http://tn5250.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool ncurses ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-os-dir=no --with-ssl=${OPENSSLBASE}

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS =/s|linux||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-data-local|:|g' ${WRKSRC}/freebsd/Makefile.in

.include <bsd.port.post.mk>
