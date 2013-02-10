# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	revelation
PORTVERSION=	0.4.14
CATEGORIES=	security gnome
MASTER_SITES=	http://cdn.bitbucket.org/erikg/revelation/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password manager for the GNOME 2 desktop

LICENSE=	GPLv2

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/security/cracklib:patch
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
LIB_DEPENDS=	crack:${PORTSDIR}/security/cracklib
RUN_DEPENDS:=	${BULID_DEPENDS}

OPTIONS_DEFINE=	APPLET
APPLET_DESC=	Build with applet

USE_BZIP2=	yes
USE_GNOME=	desktopfileutils gnomehack gnomeprefix pygnome2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_PKGCONFIG=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

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

.include <bsd.port.pre.mk>

CRACK_WRKSRC=	$$(cd ${PORTSDIR}/security/cracklib && ${MAKE} -V WRKSRC)	

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${SETENV} python|' ${WRKSRC}/src/revelation.py
	@${REINPLACE_CMD} -e \
		'/FascistCheck/s|(password)|(password, "${DICTPATH}")|' \
		${WRKSRC}/src/lib/util.py

post-build:
	@(cd ${CRACK_WRKSRC}/python && ${CC} -shared -fPIC \
		-I${PYTHON_INCLUDEDIR} -I${LOCALBASE}/include ${CFLAGS} \
		-o _cracklib.so _cracklib.c -L${LOCALBASE}/lib -lcrack -lz)
	@${PYTHON_CMD} -m compileall ${CRACK_WRKSRC}/python
	@${PYTHON_CMD} -O -m compileall ${CRACK_WRKSRC}/python

post-install:
	(cd ${CRACK_WRKSRC}/python && ${INSTALL_DATA} \
		_cracklib.so cracklib.py* \
		${PYTHONPREFIX_SITELIBDIR}/revelation)

.include <bsd.port.post.mk>
