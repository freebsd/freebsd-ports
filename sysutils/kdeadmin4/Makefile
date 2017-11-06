# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Administration applications (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=	KCRON KSYSTEMLOG KUSER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

KCRON_DESC=		Task scheduler
KCRON_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kcm_cron.so:sysutils/kcron

KSYSTEMLOG_DESC=	System log viewer
KSYSTEMLOG_RUN_DEPENDS=	${KDE_PREFIX}/bin/ksystemlog:sysutils/ksystemlog

KUSER_DESC=		User management application
KUSER_RUN_DEPENDS=	${KDE_PREFIX}/bin/kuser:sysutils/kuser

.include <bsd.port.mk>
