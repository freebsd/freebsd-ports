# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	revelation
PORTVERSION=	0.4.14
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	http://cdn.bitbucket.org/erikg/revelation/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for the GNOME 2 desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib
RUN_DEPENDS:=	${BULID_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}cracklib>0:${PORTSDIR}/security/py-cracklib

OPTIONS_DEFINE=	APPLET
APPLET_DESC=	Build with applet

USE_BZIP2=	yes
USES=		desktop-file-utils gettext pathfix pkgconfig \
		shared-mime-info shebangfix
SHEBANG_FILES= src/revelation.py
USE_GNOME=	gnomeprefix pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	revelation.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DICTPATH=	${LOCALBASE}/libdata/cracklib/pw_dict

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPPLET}
USE_GNOME+=	pygnomedesktop pygnomeextras
CONFIGURE_ARGS+=	--with-applet
GCONF_SCHEMAS+=	revelation-applet.schemas
PLIST_SUB+=	APPLET=""
.else
PLIST_SUB+=	APPLET="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/FascistCheck/s|(password)|(password, "${DICTPATH}")|' \
		${WRKSRC}/src/lib/util.py

.include <bsd.port.mk>
