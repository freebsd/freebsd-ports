# $FreeBSD$

PORTNAME=	fcgiwrap
PORTVERSION=	1.1.0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple FastCGI wrapper for CGI scripts

LICENSE=	MIT

LIB_DEPENDS=	libfcgi.so:${PORTSDIR}/www/fcgi

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	gnosek
GH_COMMIT=	333ff99
GH_TAGNAME=	${PORTVERSION}

USE_RC_SUBR=	fcgiwrap

USE_AUTOTOOLS=	aclocal autoconf autoheader

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/fcgiwrap man/man8/fcgiwrap.8.gz

post-patch:
	@${REINPLACE_CMD} 's/@prefix@@mandir@/@mandir@/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
