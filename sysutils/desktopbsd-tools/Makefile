# New ports collection Makefile for:	desktopbsd-tools
# Date created:				8 April 2006
# Whom:					Peter Hofer <ph@desktopbsd.net>
#
# $FreeBSD$

PORTNAME=	desktopbsd-tools
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.desktopbsd.net/

MAINTAINER=	ph@desktopbsd.net
COMMENT=	DesktopBSD tools for easy system configuration

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm \
		bash:${PORTSDIR}/shells/bash \
		fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup \
		portupgrade:${PORTSDIR}/sysutils/portupgrade \
		portaudit:${PORTSDIR}/security/portaudit

INSTALLS_SHLIB=	yes
USE_BZIP2=	yes
USE_KDEBASE_VER=3

QMAKE?=		qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ENV=	QTDIR="${QT_PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}
DATADIR=	${PREFIX}/share/desktopbsd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		requires FreeBSD 5 or newer
.endif

.if ${OSVERSION} < 601101 || ( ${OSVERSION} >= 700000 && ${OSVERSION} < 700015 )
RUN_DEPENDS+=	csup:${PORTSDIR}/net/csup
.endif

.if ${OSVERSION} < 504103 || ( ${OSVERSION} >= 600000 && ${OSVERSION} < 600033 )
RUN_DEPENDS+=	portsnap:${PORTSDIR}/sysutils/portsnap
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"/Installation/d; /Documentation/d; /InitialConf/d" \
		${WRKSRC}/desktopbsd.pro
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/*/*.pro

do-configure:
	@cd ${WRKSRC} \
	&& ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC} desktopbsd.pro \
	&& ${SETENV} ${MAKE_ENV} ./prepare_build.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
