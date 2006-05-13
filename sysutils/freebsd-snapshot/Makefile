# New ports collection makefile for:	freebsd-snapshot
# Date created:				2005-09-07
# Whom:					gtodd@bellanet.org
#
# $FreeBSD$
#

PORTNAME=	freebsd-snapshot
DISTVERSION=	20050402.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~rse/dist/

MAINTAINER=	gtodd@bellanet.org
COMMENT=	Convenience frontend tools for the management of UFS2 snapshots

NO_BUILD=	yes

MAN8=		snapshot.8 periodic-snapshot.8

PLIST_FILES=	sbin/snapshot \
		sbin/periodic-snapshot \
		etc/amd.map.snap

SUB_FILES=	pkg-message pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALLL=	${WRKDIR}/pkg-deinstall

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	FreeBSD lower then 5.x doesn't support snapshot
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/amd.map.snap ${WRKSRC}/snapshot \
		${WRKSRC}/periodic-snapshot ${WRKSRC}/snapshot.8 

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snapshot ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/periodic-snapshot ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/snapshot.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/periodic-snapshot.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/amd.map.snap ${PREFIX}/etc/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
