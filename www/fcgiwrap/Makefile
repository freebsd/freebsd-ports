# $FreeBSD$

PORTNAME=	fcgiwrap
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple FastCGI wrapper for CGI scripts

LICENSE=	MIT

LIB_DEPENDS=	libfcgi.so:www/fcgi

USES=		autoreconf gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	gnosek

USE_RC_SUBR=	fcgiwrap

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/fcgiwrap man/man8/fcgiwrap.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's/@prefix@@mandir@/@mandir@/'\
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/fcgiwrap

.include <bsd.port.mk>
