# $FreeBSD$

PORTNAME=	hypnotix
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	mistresssilvara@hotmail.com
COMMENT=	IPTV streaming application using mpv

LICENSE=	GPLv3 PD
LICENSE_COMB=	multi

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libxapp.so:x11/xapp
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imdbpy>0:www/py-imdbpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}

USES=		python:3.6+ shebangfix gnome
USE_GNOME=	gtk30 glib20 gdkpixbuf2 pango
GLIB_SCHEMAS=	org.x.hypnotix.gschema.xml

SHEBANG_GLOB=	*.py
INSTALLS_ICONS=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-tools
.else
BINARY_ALIAS=	msgfmt=true
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/usr/lib/${PORTNAME}/${PORTNAME}.py
	@${REINPLACE_CMD} -e 's|__DEB_VERSION__|${PORTVERSION}|g' \
		${WRKSRC}/usr/lib/${PORTNAME}/${PORTNAME}.py
	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib|g' \
		${WRKSRC}/usr/bin/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC}/usr && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
