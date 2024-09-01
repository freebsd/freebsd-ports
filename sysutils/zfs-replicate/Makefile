PORTNAME=	zfs-replicate
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	tschetter.victor@gmail.com
COMMENT=	ZFS Snapshot Replication Script
WWW=		https://github.com/aaronhurt/zfs-replicate

USES=	shebangfix

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

SHEBANG_FILES=	zfs-replicate.sh

PORTDOCS=	README.md
PORTDATA=	config.sample.sh

USE_GITHUB=	yes
GH_ACCOUNT=	aaronhurt

PLIST_FILES=	sbin/zfs-replicate

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-replicate.sh \
		${STAGEDIR}${PREFIX}/sbin/zfs-replicate

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for data in ${PORTDATA}
	${INSTALL_DATA} ${WRKSRC}/${data} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
