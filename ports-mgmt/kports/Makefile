# Created by: Hannes Hauswedell <hannes.hauswedell@gmail.com>
# $FreeBSD$

PORTNAME=	kports
PORTVERSION=	0.6.1
PORTREVISION=	10
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	SF

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	KDE3-Version of your favorite frontend to the Ports

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
CONFLICTS=	kports-0.[89]*

RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
RUN_DEPENDS+=	kdehier>=0:${PORTSDIR}/misc/kdehier

OPTIONS_DEFINE=	PORTAUDIT KDESU KDESU4 GKSU
OPTIONS_DEFAULT=	PORTAUDIT KDESU
PORTAUDIT_DESC=	Require Portaudit
KDESU_DESC=	With KDE3 kdesu
KDESU4_DESC=	With KDE4 kdesu
GKSU_DESC=	With gksu

.include <bsd.port.options.mk>

.if defined(WITH_PKGNG)
IGNORE=		only works with traditional pkg-tools
.endif

.if ! ${PORT_OPTIONS:MKDESU} && ! ${PORT_OPTIONS:MKDESU4} && ! ${PORT_OPTIONS:MGKSU}
PKGMESSAGE=	${FILESDIR}/pkg-message.nosu
.endif

.if ${PORT_OPTIONS:MPORTAUDIT}
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

.if ${PORT_OPTIONS:MKDESU}
RUN_DEPENDS+=	${LOCALBASE}/bin/kdesu:${PORTSDIR}/x11/kdebase3
.endif

.if ${PORT_OPTIONS:MKDESU4}
USE_KDE4+=	runtime
.endif

.if ${PORT_OPTIONS:MGKSU}
RUN_DEPENDS+=	${LOCALBASE}/bin/gksu:${PORTSDIR}/sysutils/gksu
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/src/kports.desktop

post-install:
.if ! ${PORT_OPTIONS:MKDESU} && ! ${PORT_OPTIONS:MKDESU4} && ! ${PORT_OPTIONS:MGKSU}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
