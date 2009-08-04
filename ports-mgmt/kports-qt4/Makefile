# New ports collection makefile for:	kports
# Date created:				Thu Jan 12 12:47:58 UTC 2006
# Whom:				Hannes Hauswedell <hannes.hauswedell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kports
PORTVERSION=	0.8.1
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	SF

MAINTAINER=	kports@soulrebel.in-berlin.de
COMMENT=	 Qt4-Version of your favorite frontend to the Ports

RUN_DEPENDS=	portaudit:${PORTSDIR}/ports-mgmt/portaudit

CONFLICTS=	kports-0.[0-7]*

USE_BZIP2=	yes

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qmake_build moc_build uic_build rcc_build
QMAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes

LATEST_LINK=	kports-qt4

OPTIONS=	DEBUG "Add Debugging Symbols" off \
		KDE "Pull in kdebase-runtime" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_KDE)
RUN_DEPENDS+=   ${LOCALBASE}/kde4/lib/kde4/libexec/kdesu:${PORTSDIR}/x11/kdebase4-runtime
.else
PKGMESSAGE=	pkg-message.nokdebase
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/data/kports.desktop

.if defined(WITH_DEBUG)
pre-configure:
	@(${ECHO_CMD} "CONFIG += debug" >> ${WRKSRC}/src/src.pro)
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix ${QMAKE_ARGS} kports.pro

post-install:
.if defined(WITHOUT_KDE)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
