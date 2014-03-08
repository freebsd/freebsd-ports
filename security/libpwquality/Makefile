# $FreeBSD$

PORTNAME=	libpwquality
PORTVERSION=	1.2.3
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libpwquality/

MAINTAINER=	gnome@freebsd.org
COMMENT=	Library for generating random passwords and quality checking

LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib

USES=		gettext gmake libtool pathfix
USE_BZIP2=	yes
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-pam
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# configure needs to be fixed
CONFIGURE_ENV+=	LIBS="-lintl"

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
CONFIGURE_ARGS+=--enable-python-bindings
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python-bindings
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|python setup.py build|${PYTHON_VERSION} setup.py build|g' \
		${WRKSRC}/python/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpwquality.so.1
	@${CHMOD} 755 ${STAGEDIR}${PYTHON_SITELIBDIR}/pwquality.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pwquality.so

.include <bsd.port.mk>
