# Created by: gtodd@bellanet.org
# $FreeBSD$

PORTNAME=	freebsd-snapshot
DISTVERSION=	20091208.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~rse/dist/

MAINTAINER=	gtodd@bellanet.org
COMMENT=	Convenience frontend tools for the management of UFS2 snapshots

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message pkg-deinstall

PLIST_FILES=	etc/amd.map.snap man/man8/periodic-snapshot.8.gz \
		man/man8/snapshot.8.gz sbin/periodic-snapshot sbin/snapshot

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/amd.map.snap ${WRKSRC}/snapshot \
		${WRKSRC}/periodic-snapshot ${WRKSRC}/snapshot.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snapshot ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/periodic-snapshot ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/snapshot.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/periodic-snapshot.8 \
		${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/amd.map.snap ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
