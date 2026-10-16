PORTNAME=	snapraid
DISTVERSION=	15.0
CATEGORIES=	sysutils archivers
MASTER_SITES=	https://github.com/amadvance/snapraid/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	File-level Backup/RAID program for disk arrays
WWW=		https://www.snapraid.it/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	gmake:devel/gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
TEST_TARGET=	check
# test suite wants gmake, but port builds fine without
DO_MAKE_TEST?=	${SETENVI} ${WRK_ENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} \
			${MAKEFILE} ${TEST_ARGS:N${DESTDIRNAME}=*}

post-install:
	${INSTALL_DATA} ${WRKSRC}/snapraid.conf.example ${STAGEDIR}${PREFIX}/etc/snapraid.conf.sample

.include <bsd.port.mk>
