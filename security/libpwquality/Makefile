PORTNAME=	libpwquality
DISTVERSION=	1.4.4
CATEGORIES=	security
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for generating random passwords and quality checking

LICENSE=	GPLv2+ LIBPWQUALITY
LICENSE_COMB=	dual
LICENSE_NAME_LIBPWQUALITY=	The libpwquality license
LICENSE_FILE_LIBPWQUALITY=	${WRKSRC}/COPYING
LICENSE_PERMS_LIBPWQUALITY=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libcrack.so:security/cracklib

USES=		cpe gmake libtool localbase pathfix tar:bz2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPE_VENDOR=	libpwquality_project
CONFIGURE_ARGS+=--disable-pam
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS PYTHON
OPTIONS_DEFAULT=NLS PYTHON
OPTIONS_SUB=	yes
NLS_USES=	gettext gnome
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=	python
PYTHON_CONFIGURE_ENABLE=	python-bindings
PYTHON_CONFIGURE_ON=	--with-python-binary=${PYTHON_CMD}

.include <bsd.port.mk>
