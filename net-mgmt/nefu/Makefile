# New ports collection makefile for:	nefu
# Date created:				17.10.2003
# Whom:					Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nefu
PORTVERSION=	0.9.6
CATEGORIES=	net
MASTER_SITES=	http://rsug.itd.umich.edu/software/nefu/files/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A network monitoring daemon

USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE} --disable-html
USE_OPENSSL=	yes
USE_LIBTOOL=	yes

MAN1=		nefu.1
MAN4=		nefu.conf.4
PLIST_FILES=	bin/nefu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nefu.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nefu.conf.4 ${PREFIX}/man/man4

.include <bsd.port.mk>
