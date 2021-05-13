PORTNAME=	libvmod-dynamic
PORTVERSION=	20210513
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Varnish Module (vmod) for dynamic backends

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: objects
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: objects

LIB_DEPENDS=	libgetdns.so:dns/getdns
BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=		autoreconf compiler:c11 gmake libtool pkgconfig \
		python:3.5+,build varnish:6
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
DOCSDIR=	${PREFIX}/share/doc/vmod-dynamic
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${WRKSRC}/src

USE_GITHUB=	yes
GH_ACCOUNT=	nigoroll
GH_TAGNAME=	1bf8f07

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's|$${VARNISHAPI_DATAROOTDIR}|${LOCALBASE}/share|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
