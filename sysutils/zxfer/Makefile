PORTNAME=	zxfer
PORTVERSION=	1.1.7
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@scaleengine.com
COMMENT=	Easily and reliably transfer ZFS filesystems
WWW=		https://github.com/allanjude/zxfer

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	allanjude

NO_BUILD=	yes

OPTIONS_DEFINE=	RSYNC

RSYNC_DESC=		Enable RSYNC Support
RSYNC_RUN_DEPENDS=	rsync:net/rsync

PLIST_FILES=	share/man/man8/zxfer.8.gz \
		sbin/zxfer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zxfer ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zxfer.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
