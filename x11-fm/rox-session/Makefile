# New ports collection makefile for:	rox-session
# Date created:        11 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-session
PORTVERSION=	0.40.0
CATEGORIES=	x11-fm
MASTER_SITES=	SF/rox/ROX-Session/${PORTVERSION}/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple session manager for the ROX desktop

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

WRKSRC=		${WRKDIR}/ROX-Session
DATADIR=	${PREFIX}/apps/ROX-Session

USE_GNOME=	gtk20 libxml2
USE_XORG=	x11 xext xtst xxf86vm
USE_PYTHON=	yes

PORTDOCS=	Changes DBUS-API README

.if !exists(${LOCALBASE}/sbin/gdm)
OPTIONS_DEFINE=	GDM
GDM_DESC=	Install GDM login manager
.endif

SUB_FILES=	${PORTNAME} rox.desktop

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

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdmu ${DATADIR}
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKDIR}/rox.desktop ${PREFIX}/share/applications
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/Help/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
