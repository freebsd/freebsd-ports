# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmd
PORTVERSION=	0.5
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

OPTIONS_DEFINE=		DOCS PTP MTP NTFS EXFAT
OPTIONS_DEFAULT=	PTP MTP NTFS
PTP_DESC=		Picture Transfer Protocol support
NTFS_DESC=		Mount NTFS filesystems with read and write support
EXFAT_DESC=		exFAT filesystem support
PTP_RUN_DEPENDS=	gphotofs:graphics/fusefs-gphotofs
MTP_RUN_DEPENDS=	simple-mtpfs:sysutils/fusefs-simple-mtpfs
NTFS_RUN_DEPENDS=	ntfs-3g:sysutils/fusefs-ntfs
EXFAT_RUN_DEPENDS=	mount.exfat:sysutils/fusefs-exfat

.include <bsd.port.mk>
