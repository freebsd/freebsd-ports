# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Administration applications (meta port)

USE_KDE4=	# blank, needed to get KDE4_VERSION
USES=		metaport

OPTIONS_DEFINE=	KCRON KSYSTEMLOG KUSER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

KCRON_DESC=		Task scheduler
KCRON_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kcm_cron.so:sysutils/kcron

KSYSTEMLOG_DESC=	System log viewer
KSYSTEMLOG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ksystemlog:sysutils/ksystemlog

KUSER_DESC=		User management application
KUSER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kuser:sysutils/kuser

.include <bsd.port.mk>
