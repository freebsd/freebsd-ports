# Ports collection makefile for:	sobby
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	sobby
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://releases.0x539.de/sobby/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A standalone obby server

LIB_DEPENDS=	net6:${PORTSDIR}/net/net6 \
		obby:${PORTSDIR}/devel/obby \
		xml++:${PORTSDIR}/textproc/libxml++26 \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		glibmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

MAN1=	sobby.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sobby

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sobby ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sobby.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
