# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	istatd
PORTVERSION=	0.5.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES= GHC

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Daemon for iStat iPhone application

LICENSE=    BSD3CLAUSE

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USE_GITHUB= yes
GH_ACCOUNT= tiwilliam

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/istatd etc/istat.conf-dist man/man1/istatd.1.gz \
		man/man5/istat.conf.5.gz

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/istatd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/istatd ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/resource/istat.conf \
		${STAGEDIR}${PREFIX}/etc/istat.conf-dist
	${INSTALL_MAN} ${WRKSRC}/resource/istatd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/resource/istat.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>
