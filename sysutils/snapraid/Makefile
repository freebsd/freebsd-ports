PORTNAME=	snapraid
DISTVERSION=	12.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	https://github.com/amadvance/snapraid/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	File-level Backup/RAID program for disk arrays

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/snapraid \
		man/man1/snapraid.1.gz \
		etc/snapraid.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/snapraid.conf.example ${STAGEDIR}${PREFIX}/etc/snapraid.conf.sample

.include <bsd.port.mk>
