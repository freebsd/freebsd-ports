# Ports collection makefile for:	sobby
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	sobby
PORTVERSION=	0.4.7
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://releases.0x539.de/sobby/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A standalone obby server

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		obby-0.4.1:${PORTSDIR}/devel/obby \
		net6-1.3.0:${PORTSDIR}/net/net6 \
		xml++-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		glibmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-zeroconf
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
