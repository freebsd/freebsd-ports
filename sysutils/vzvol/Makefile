# $FreeBSD$

PORTNAME=		vzvol
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.5
CATEGORIES=		sysutils

MAINTAINER=		rainbow@purlinux.org
COMMENT=		Feature-rich ZFS zvol management tool

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

GROUPS=			operator

USE_GITHUB=		yes
GH_ACCOUNT=		RainbowHackerHorse
NO_BUILD=		yes
NO_ARCH=		yes

PORTDOCS=		README.md CONTRIBUTORS

OPTIONS_DEFINE=			DOCS PROGRESS VIRTUALBOX
OPTIONS_GROUP=			FILESYSTEMS
OPTIONS_GROUP_FILESYSTEMS=	EXT XFS
OPTIONS_DEFAULT=		EXT PROGRESS VIRTUALBOX XFS

EXT_RUN_DEPENDS=		mke2fs:sysutils/e2fsprogs
PROGRESS_RUN_DEPENDS=		pv:sysutils/pv
VIRTUALBOX_RUN_DEPENDS=		virtualbox:emulators/virtualbox-ose
XFS_RUN_DEPENDS=		mkfs.xfs:sysutils/xfsprogs

EXT_DESC=			Install support for ext2, ext3, and ext4
PROGRESS_DESC=			Enables progress bars for import
VIRTUALBOX_DESC=		Support .VMDK creation with VirtualBox tools
XFS_DESC=			Install support for XFS Filesystem

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vzvol ${STAGEDIR}${PREFIX}/bin
.for dir in shared freebsd linux
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vzvol/lib/${dir}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/${dir}/* ${STAGEDIR}${PREFIX}/lib/vzvol/lib/${dir}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
