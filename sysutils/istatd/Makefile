# New ports collection makefile for:	istatd
# Date created:		2009-12-01
# Whom:			Babak Farrokhi <farrokhi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	istatd
PORTVERSION=	0.5.4
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Daemon for iStat iPhone application

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

MAN1=		istatd.1
MAN5=		istat.conf.5

PLIST_FILES=	bin/istatd etc/istat.conf-dist
SUB_FILES+=	pkg-message

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/istatd ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKDIR}/istatd ${PREFIX}/etc/rc.d
		${INSTALL_DATA} ${WRKSRC}/resource/istat.conf ${PREFIX}/etc/istat.conf-dist
		${INSTALL_MAN} ${WRKSRC}/resource/istatd.1 ${MAN1PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/resource/istat.conf.5 ${MAN5PREFIX}/man/man5

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
