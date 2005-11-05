# Ports collection makefile for:	sobby
# Date created:				2005-10-14
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	sobby
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://releases.0x539.de/sobby/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A standalone obby server

LIB_DEPENDS=	net6:${PORTSDIR}/net/net6 \
		obby:${PORTSDIR}/devel/obby \
		sigc++-2.0:${PORTSDIR}/devel/libsigc++20 \
		glibmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/sobby

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	"Some dependencies does not run on FreeBSD \< 5.x"
.endif

.include <bsd.port.post.mk>
