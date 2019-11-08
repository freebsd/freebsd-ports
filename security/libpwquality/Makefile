# $FreeBSD$

PORTNAME=	libpwquality
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for generating random passwords and quality checking

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		gettext gmake gnome libtool localbase pathfix tar:bz2
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--disable-pam
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes
PYTHON_USES=	python
PYTHON_CONFIGURE_ENABLE=	python-bindings
PYTHON_CONFIGURE_ON=	--with-python-binary=${PYTHON_CMD}

.include <bsd.port.mk>
