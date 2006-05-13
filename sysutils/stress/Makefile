# New ports collection makefile for:	stress
# Date created:				18 May 2004
# Whom:					Dmitri Nikulin <setagllib@optusnet.com.au>
#
# $FreeBSD$
#

PORTNAME=	stress
PORTVERSION=	0.18.8
CATEGORIES=	sysutils
MASTER_SITES=	http://weather.ou.edu/~apw/projects/stress/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	Tool to impose load on and stress test Unix-like systems

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build ${MACHINE_ARCH}-portbld-freebsd${OSREL}

INFO=		stress
MAN1=		stress.1
PLIST_FILES=	bin/stress

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CFLAGS\ \)=|\1 +=|; s|^\(CFLAGS.*\)-Wall|\1|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
