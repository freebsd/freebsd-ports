# $FreeBSD$

PORTNAME=	fcgiwrap
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Simple FastCGI wrapper for CGI scripts

LICENSE=	MIT

LIB_DEPENDS=	libfcgi.so:www/fcgi

USES=		autoreconf gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	gnosek

USE_RC_SUBR=	fcgiwrap

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/fcgiwrap man/man8/fcgiwrap.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's/@prefix@@mandir@/@mandir@/'\
	-e 's|-m 755 fcgiwrap|-s -m 755 fcgiwrap|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
