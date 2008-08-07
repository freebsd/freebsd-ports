# New ports collection makefile for:	isc-cron
# Date created:				7 August 2008
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	isc-cron
PORTVERSION=	4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_ISC}
DISTNAME=	cron_${PORTVERSION}.shar
EXTRACT_SUFX=

MAINTAINER=	edwin@mavetju.org
COMMENT=	ISC Cron, former Vixie Cron

WRKSRC=		${WRKDIR}
SUB_FILES=	pkg-message
PLIST_FILES=	sbin/cron bin/crontab
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		crontab.1
MAN5=		crontab.5
MAN8=		cron.8

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${SH} ${DISTDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cron ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/crontab ${PREFIX}/bin
	${CHOWN} root ${PREFIX}/bin/crontab
	${CHMOD} 4555 ${PREFIX}/bin/crontab
	${INSTALL_MAN} ${WRKSRC}/crontab.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/crontab.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/cron.8 ${PREFIX}/man/man8

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
