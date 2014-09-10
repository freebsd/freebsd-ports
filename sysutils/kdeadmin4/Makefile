# $FreeBSD$

PORTNAME=	kdeadmin
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	sysutils kde
DISTFILES=	#

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Administration applications (meta port)

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	KCRON KSYSTEMLOG KUSER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

KCRON_DESC=		Task scheduler
KCRON_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kcm_cron.so:${PORTSDIR}/sysutils/kcron

KSYSTEMLOG_DESC=	System log viewer
KSYSTEMLOG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ksystemlog:${PORTSDIR}/sysutils/ksystemlog

KUSER_DESC=		User management application
KUSER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kuser:${PORTSDIR}/sysutils/kuser

.include <bsd.port.mk>
