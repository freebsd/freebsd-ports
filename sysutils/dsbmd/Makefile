# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmd
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Media mounting daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz

USE_RC_SUBR=	dsbmd

PORTDOCS=	README
PLIST_FILES=	libexec/dsbmd "@sample etc/dsbmd.conf.sample"

OPTIONS_DEFINE=		DOCS EXFAT EXT4 MTP NTFS PTP
OPTIONS_DEFAULT=	EXT4 MTP NTFS PTP

EXFAT_DESC=		exFAT filesystem support
EXT4_DESC=		Ext4 filesystem support
NTFS_DESC=		Mount NTFS filesystems with read and write support
PTP_DESC=		Picture Transfer Protocol support

EXFAT_RUN_DEPENDS=	mount.exfat:sysutils/fusefs-exfat
EXT4_RUN_DEPENDS=	fuse-ext2:sysutils/fusefs-ext2
MTP_RUN_DEPENDS=	simple-mtpfs:sysutils/fusefs-simple-mtpfs
NTFS_RUN_DEPENDS=	ntfs-3g:sysutils/fusefs-ntfs
PTP_RUN_DEPENDS=	gphotofs:graphics/fusefs-gphotofs

.include <bsd.port.mk>
