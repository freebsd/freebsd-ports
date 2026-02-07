PORTNAME=	iksemel
PORTVERSION=	1.5
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML parser library mainly designed for Jabber applications
WWW=		https://github.com/meduketto/iksemel

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		autoreconf libtool localbase:ldflags pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	meduketto
GH_TAGNAME=	978b733
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gnutls=yes \
		--without-openssl \
		--disable-python

INSTALL_TARGET=	install-strip

CPPFLAGS+=	${CXXFLAGS}

OPTIONS_DEFINE=		INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=	makeinfo
INFO_INFO=	iksemel

post-patch-INFO-on:
	@${REINPLACE_CMD} -e 's|@setfilename iksemel|@setfilename iksemel.info|' \
	    ${WRKSRC}/doc/iksemel.texi

post-patch-INFO-off:
	@${REINPLACE_CMD} -e '/SUBDIRS/s|doc||' \
	    ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
