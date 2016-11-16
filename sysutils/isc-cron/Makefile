# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	isc-cron
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ISC/cron
DISTNAME=	cron_${PORTVERSION}.shar
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISC Cron, former Vixie Cron

WRKSRC=		${WRKDIR}
SUB_FILES=	pkg-message
PLIST_FILES=	sbin/cron bin/crontab man/man1/crontab.1.gz \
		man/man5/crontab.5.gz man/man8/cron.8.gz
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${SH} ${DISTDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cron ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/crontab ${STAGEDIR}${PREFIX}/bin
	${CHMOD} 4555 ${STAGEDIR}${PREFIX}/bin/crontab
	${INSTALL_MAN} ${WRKSRC}/crontab.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/crontab.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/cron.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
