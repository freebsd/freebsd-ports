PORTNAME=	fcgiwrap
PORTVERSION=	1.1.0
PORTREVISION=	12
CATEGORIES=	www

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Simple FastCGI wrapper for CGI scripts
WWW=		http://nginx.localdomain.pl/wiki/FcgiWrap

LICENSE=	MIT

LIB_DEPENDS=	libfcgi.so:www/fcgi

USES=		autoreconf gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	gnosek

USE_RC_SUBR=	fcgiwrap

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	share/man/man8/fcgiwrap.8.gz \
		sbin/fcgiwrap

post-patch:
	@${REINPLACE_CMD} -e 's/@prefix@@mandir@/@mandir@/'\
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/fcgiwrap

.include <bsd.port.mk>
