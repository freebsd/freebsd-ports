# Created by: Slawomir Wojciech Wojtczak <vermaden@interia.pl>
# $FreeBSD$

PORTNAME=	automount
PORTVERSION=	1.4.3
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.github.com/vermaden/automount/master/ \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	vermaden@interia.pl
COMMENT=	FreeBSD's devd(8) based automount solution

LICENSE=	BSD

PLIST_FILES=	sbin/automount etc/devd/automount_devd.conf etc/automount.conf.sample

NO_BUILD=	yes

OPTIONS_DEFINE=		NTFS3G EXT4 EXFAT
OPTIONS_DEFAULT=	NTFS3G EXT4 EXFAT
NTFS3G_DESC=		Enable NTFS write support with ntfs-3g over FUSE
EXT4_DESC=		Support EXT4 filesystem
EXFAT_DESC=		Support Microsoft exFAT filesystem

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNTFS3G}
RUN_DEPENDS+=	fusefs-ntfs>=0:${PORTSDIR}/sysutils/fusefs-ntfs
.endif

.if ${PORT_OPTIONS:MEXT4}
RUN_DEPENDS+=	fusefs-ext4fuse>=0:${PORTSDIR}/sysutils/fusefs-ext4fuse
.endif

.if ${PORT_OPTIONS:MEXFAT}
RUN_DEPENDS+=	fusefs-exfat>=0:${PORTSDIR}/sysutils/fusefs-exfat
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/automount             ${PREFIX}/sbin
	${INSTALL_DATA}   ${WRKSRC}/automount_devd.conf   ${PREFIX}/etc/devd/automount_devd.conf
	${INSTALL_DATA}   ${WRKSRC}/automount.conf.sample ${PREFIX}/etc/automount.conf.sample
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
