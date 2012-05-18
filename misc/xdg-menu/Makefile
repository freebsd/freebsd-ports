# New Ports collection makefile for:	XDG-Menu
# Date created:		2012-05-07
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	menu
PORTVERSION=	1.5
CATEGORIES=	misc
MASTER_SITES=	SF/xdg-menu/xdg-menu/${PORTVERSION}
PKGNAMEPREFIX=	xdg-
DISTNAME=	XDG-Menu-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A ROX panel applet that displays an applications menu button

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

WRKSRC=		${WRKDIR}/XDG-Menu
DATADIR=	${PREFIX}/apps/XDG-Menu

FETCH_ARGS?=	-Fpr
USE_PYTHON=	yes
ALL_TARGET=
NO_BUILD=	yes

OPTIONS=	ROX	"Enable ROX panel applet support" no

.include <bsd.port.options.mk>

.if defined(WITHOUT_ROX)
post-patch:
	@${REINPLACE_CMD} -i '' '/if not rox.confirm/,/sys.exit/s/^/#/' ${WRKSRC}/AppRun
	@${ECHO_MSG}
	@${ECHO_MSG} "You have not enabled ROX panel applet support"
	@${ECHO_MSG}
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.endif

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./AppRun\n" > ${WRKDIR}/xdg-menu.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/xdg-menu.sh ${PREFIX}/bin/xdg-menu
# Executable and Data
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdmu ${DATADIR}

.include <bsd.port.mk>
