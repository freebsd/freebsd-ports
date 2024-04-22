PORTNAME=	bwm-ng
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.gropp.org/bwm-ng/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Small and simple bandwidth monitor
WWW=		https://www.gropp.org/?id=projects&sub=bwm-ng

LICENSE=	GPLv2+

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		autoreconf ncurses pkgconfig
USE_CSTD=	gnu89
PLIST_FILES=	bin/bwm-ng share/man/man1/bwm-ng.1.gz

CONFIGURE_ARGS=	--with-libstatgrab
CPPFLAGS+=	`pkg-config --cflags libstatgrab`
LIBS+=		`pkg-config --libs libstatgrab`

.include <bsd.port.mk>
