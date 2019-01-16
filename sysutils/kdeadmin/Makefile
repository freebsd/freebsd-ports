# $FreeBSD$

PORTNAME=	kdeadmin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}$
PORTREVISION=	1
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Administration applications (meta port)

USES=		kde:5 metaport

OPTIONS_DEFINE=		KCRON KSYSTEMLOG
OPTIONS_DEFAULT=	KCRON KSYSTEMLOG

KCRON_DESC=		Task scheduler
KCRON_RUN_DEPENDS=	kcron>=${KDE_APPLICATIONS_VERSION}:sysutils/kcron

KSYSTEMLOG_DESC=	System log viewer
KSYSTEMLOG_RUN_DEPENDS=	ksystemlog>=${KDE_APPLICATIONS_VERSION}:sysutils/ksystemlog

.include <bsd.port.mk>
