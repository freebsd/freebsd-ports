# New ports collection makefile for:	kports
# Date created:				Thu Jan 12 12:47:58 UTC 2006
# Whom:				Hannes Hauswedell <hannes.hauswedell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kports
PORTVERSION=	0.6.1
PORTREVISION=	8
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	SF

MAINTAINER=	kports@soulrebel.in-berlin.de
COMMENT=	KDE3-Version of your favorite frontend to the Ports

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
CONFLICTS=	kports-0.[89]*

RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
RUN_DEPENDS+=	kdehier>=0:${PORTSDIR}/misc/kdehier

OPTIONS=	PORTAUDIT "Require Portaudit" on \
		KDESU "With KDE3 kdesu" on \
		KDESU4 "With KDE4 kdesu" off \
		GKSU "With gksu" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_KDESU) && defined(WITHOUT_KDESU4) && defined(WITHOUT_GKSU)
PKGMESSAGE=	${FILESDIR}/pkg-message.nosu
.endif

.if !defined(WITHOUT_PORTAUDIT)
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

.if defined(WITH_KDESU)
RUN_DEPENDS+=	${LOCALBASE}/bin/kdesu:${PORTSDIR}/x11/kdebase3
.endif

.if defined(WITH_KDESU4)
RUN_DEPENDS+=	${LOCALBASE}/kde4/lib/kde4/libexec/kdesu:${PORTSDIR}/x11/kdebase4-runtime
.endif

.if defined(WITH_GKSU)
RUN_DEPENDS+=	${LOCALBASE}/bin/gksu:${PORTSDIR}/sysutils/gksu
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/src/kports.desktop

post-install:
.if defined(WITHOUT_KDESU) && defined(WITHOUT_KDESU4) && defined(WITHOUT_GKSU)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
