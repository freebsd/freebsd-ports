# $FreeBSD$

PORTNAME=	libpwquality
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/releases/l/i/libpwquality/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for generating random passwords and quality checking

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		gettext gmake libtool pathfix tar:bzip2
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-pam
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes
PYTHON_USES=	python
PYTHON_CONFIGURE_ENABLE=	python-bindings
PYTHON_CONFIGURE_ON=	--with-python-binary=${PYTHON_CMD}

.include <bsd.port.mk>
