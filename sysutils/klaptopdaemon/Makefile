# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	klaptopdaemon
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
PKGNAMEPREFIX=	kdeutils-
DISTNAME=	kdeutils-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	APM monitor for KDE

OPTIONS_DEFINE_i386=	ACPI
ACPI_DESC=	Contributed ACPI support patch

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3

ONLY_FOR_ARCHS=	i386
USE_XORG=	xtst xscrnsaver
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kdeutils-${PORTVERSION}

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MACPI} || ${ARCH} == "amd64"
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-acpi-support
ONLY_FOR_ARCHS+=amd64
.endif

pre-configure:
	${ECHO_CMD} ${PORTNAME} > ${WRKSRC}/inst-apps

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
