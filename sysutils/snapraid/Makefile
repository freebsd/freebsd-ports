PORTNAME=	snapraid
DISTVERSION=	13.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	https://github.com/amadvance/snapraid/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	File-level Backup/RAID program for disk arrays
WWW=		https://www.snapraid.it/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
TEST_TARGET=	check

PLIST_FILES=	bin/snapraid \
		share/man/man1/snapraid.1.gz \
		etc/snapraid.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/snapraid.conf.example ${STAGEDIR}${PREFIX}/etc/snapraid.conf.sample

.include <bsd.port.mk>
