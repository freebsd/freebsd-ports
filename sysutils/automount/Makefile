# Created by: Slawomir Wojciech Wojtczak <vermaden@interia.pl>
# $FreeBSD$

PORTNAME=	automount
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.github.com/vermaden/automount/master/ \
		LOCAL/madpilot/${PORTNAME}/

MAINTAINER=	vermaden@interia.pl
COMMENT=	FreeBSD's devd(8) based automount solution

LICENSE=	BSD2CLAUSE

PLIST_FILES=	sbin/automount etc/devd/automount_devd.conf etc/automount.conf.sample

SUB_FILES=	pkg-install
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		NTFS3G EXT4 EXFAT
OPTIONS_DEFAULT=	NTFS3G EXT4
NTFS3G_DESC=		Enable NTFS write support with ntfs-3g over FUSE
NTFS3G_RUN_DEPENDS=	fusefs-ntfs>=0:sysutils/fusefs-ntfs
EXT4_DESC=		Support EXT4 filesystem
EXT4_RUN_DEPENDS=	fusefs-ext4fuse>=0:sysutils/fusefs-ext4fuse
EXFAT_DESC=		Support Microsoft exFAT filesystem
EXFAT_RUN_DEPENDS=	fusefs-exfat>=0:sysutils/fusefs-exfat

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/automount             ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA}   ${WRKDIR}/automount_devd.conf   ${STAGEDIR}${PREFIX}/etc/devd/automount_devd.conf
	${INSTALL_DATA}   ${WRKDIR}/automount.conf	  ${STAGEDIR}${PREFIX}/etc/automount.conf.sample

.include <bsd.port.mk>

