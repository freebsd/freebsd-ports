PORTNAME=	snapraid
DISTVERSION=	15.1
CATEGORIES=	sysutils archivers
MASTER_SITES=	https://github.com/amadvance/snapraid/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	File-level Backup/RAID program for disk arrays
WWW=		https://www.snapraid.it/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/snapraid.conf.example ${STAGEDIR}${PREFIX}/etc/snapraid.conf.sample

.include <bsd.port.mk>
