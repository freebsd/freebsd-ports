# Created by: Peter Ankerstal <peter@pean.org>
# $FreeBSD$

PORTNAME=	zfs-periodic
PORTVERSION=	1.0.20130213
CATEGORIES=	sysutils

MAINTAINER=	peter@pean.org
COMMENT=	Simple way of maintaining zfs snapshots using the periodic system

USE_GITHUB=	yes
GH_ACCOUNT=	ross
GH_TAGNAME=	a481121

NO_ARCH=	yes
NO_BUILD=	yes

PERIODIC_DIRS=	etc/periodic/hourly etc/periodic/daily \
		etc/periodic/weekly etc/periodic/monthly \
		etc/periodic

PERIODIC_FILES=	etc/periodic/hourly/000.zfs-snapshot \
		etc/periodic/daily/000.zfs-snapshot \
		etc/periodic/weekly/000.zfs-snapshot \
		etc/periodic/monthly/000.zfs-snapshot

PLIST_FILES=	${PERIODIC_FILES} bin/zfs-snapshot

post-patch:
.for _file in ${PERIODIC_FILES}
	@${REINPLACE_CMD} -e "s|/etc/periodic/zfs-snapshot|${PREFIX}/bin/zfs-snapshot|" \
		${WRKSRC}/${_file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/etc/periodic/zfs-snapshot ${STAGEDIR}${PREFIX}/bin
.for _dir in ${PERIODIC_DIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${_dir}
.endfor

.for _file in ${PERIODIC_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${_file} ${STAGEDIR}${PREFIX}/${_file}
.endfor

.include <bsd.port.mk>
