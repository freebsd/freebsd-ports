PORTNAME=	plocate
DISTVERSION=	1.1.19
CATEGORIES=	sysutils
MASTER_SITES=	https://plocate.sesse.net/download/

MAINTAINER=	sec@42.org
COMMENT=	Fast & privacy-respecting locate utility
WWW=		https://plocate.sesse.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	meson:devel/meson
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		meson pkgconfig
MESON_ARGS=	--sharedstatedir=/var/db

SUB_FILES=	315.plocate

GROUPS=		plocate

post-patch:
	${CP} ${FILESDIR}/mntent_compat.c++ ${FILESDIR}/mntent.h ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/315.plocate \
		${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_DATA} ${FILESDIR}/updatedb.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}/var/db/plocate

.include <bsd.port.mk>
