# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	revelation
PORTVERSION=	0.4.14
PORTREVISION=	4
CATEGORIES=	security gnome
MASTER_SITES=	https://bitbucket.org/erikg/revelation/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for the GNOME 2 desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto
LIB_DEPENDS=	libcrack.so:security/cracklib
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}cracklib>0:security/py-cracklib

USES=		desktop-file-utils gettext gmake pathfix pkgconfig python \
		shared-mime-info shebangfix tar:bzip2
SHEBANG_FILES=	src/revelation.py
USE_GNOME=	gnomeprefix pygnome2 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-applet --disable-desktop-update --disable-mime-update

GCONF_SCHEMAS=	revelation.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DICTPATH=	${LOCALBASE}/libdata/cracklib/pw_dict

post-patch:
	@${REINPLACE_CMD} -e \
		'/FascistCheck/s|(password)|(password, "${DICTPATH}")|' \
		${WRKSRC}/src/lib/util.py

.include <bsd.port.mk>
