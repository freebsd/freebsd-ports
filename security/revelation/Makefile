# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	revelation
PORTVERSION=	0.4.14
PORTREVISION=	3
CATEGORIES=	security gnome
MASTER_SITES=	http://cdn.bitbucket.org/erikg/revelation/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for the GNOME 2 desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib
RUN_DEPENDS:=	${BULID_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}cracklib>0:${PORTSDIR}/security/py-cracklib

USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:bzip2 \
		shared-mime-info shebangfix
SHEBANG_FILES= src/revelation.py
USE_GNOME=	gnomeprefix pygnome2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-applet

GCONF_SCHEMAS=	revelation.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DICTPATH=	${LOCALBASE}/libdata/cracklib/pw_dict

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/FascistCheck/s|(password)|(password, "${DICTPATH}")|' \
		${WRKSRC}/src/lib/util.py

.include <bsd.port.mk>
