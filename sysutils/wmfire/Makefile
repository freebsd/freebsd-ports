# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	wmfire
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.swanson.ukfsn.org/wmfire/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dock app showing load average as a flame

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

PLIST_FILES=	bin/wmfire man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
