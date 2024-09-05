PORTNAME=	freetalk
PORTVERSION=	4.2
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	GNU/freetalk

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	GNU console based Jabber client
WWW=		https://www.gnu.org/software/freetalk/

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl-1.3.texi

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libloudmouth-1.so:net-im/loudmouth

USES=		autoreconf gettext-runtime gnome guile:2.2 localbase \
		makeinfo ncurses pkgconfig readline
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

LIBS=		-largp
INFO=		freetalk

post-patch:
	@${REINPLACE_CMD} -e 's,guile-2\.0,guile-2.2,' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
