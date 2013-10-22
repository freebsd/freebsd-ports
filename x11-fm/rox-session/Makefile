# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.40.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/rox/ROX-Session/${PORTVERSION}/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple session manager for the ROX desktop

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}roxlib>=0:${PORTSDIR}/devel/py-roxlib \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus

WRKSRC=		${WRKDIR}/ROX-Session
DATADIR=	${PREFIX}/apps/ROX-Session

USES=		pkgconfig
USE_GNOME=	gtk20 libxml2
USE_XORG=	x11 xext xtst xxf86vm
USE_PYTHON=	yes

PORTDOCS=	Changes DBUS-API README

OPTIONS_DEFINE=	GDM
GDM_DESC=	Install GDM login manager

SUB_FILES=	${PORTNAME} rox.desktop

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDM}
RUN_DEPENDS+=	${LOCALBASE}/sbin/gdm:${PORTSDIR}/x11/gdm
PLIST_SUB+=	GDM=""
.else
PLIST_SUB+=	GDM="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@cd ${WRKSRC} && ./AppRun --compile
	@${MKDIR} ${WRKSRC}/Messages
	@cd ${WRKSRC}/src/po && ./dist

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${CP} -r .DirIcon AppInfo.xml AppRun \
		Environment Login Messages Options.xml ROX-Session \
		ROX-Session.xml RunROX SetupPanel Styles browser images \
		*.py *.pyc *.pyo ${DATADIR}
.if ${PORT_OPTIONS:MGDM}
	@${INSTALL_DATA} ${WRKDIR}/rox.desktop ${PREFIX}/share/applications
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/Help/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
