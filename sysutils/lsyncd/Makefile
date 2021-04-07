PORTNAME=	lsyncd
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.2.3
CATEGORIES=	sysutils

MAINTAINER=	junichi@junichi.org
COMMENT=	Live Syncing (Mirror) Daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cmake localbase lua
USE_GITHUB=	yes
GH_ACCOUNT=	axkibe
USE_RC_SUBR=	lsyncd

CFLAGS+=	-D__BSD_VISIBLE # for DT_{UNKNOWN,DIR}
PLIST_FILES=	sbin/lsyncd \
		man/man1/lsyncd.1.gz \
		"@sample etc/lsyncd.conf.sample"

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/default-rsync.lua
	
post-install:
	${INSTALL_DATA} ${FILESDIR}/lsyncd.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
