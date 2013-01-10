# Created by: Slawomir Wojciech Wojtczak <vermaden@interia.pl>
# $FreeBSD$

PORTNAME=	automount
PORTVERSION=	1.4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.github.com/vermaden/automount/master/ \
		LOCAL/bdrewery/${PORTNAME}/

MAINTAINER=	vermaden@interia.pl
COMMENT=	FreeBSD's devd(8) based automount solution

LICENSE=	BSD

PLIST_FILES=	sbin/automount etc/devd/automount_devd.conf etc/automount.conf.sample

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/automount             ${PREFIX}/sbin
	${INSTALL_DATA}   ${WRKSRC}/automount_devd.conf   ${PREFIX}/etc/devd/automount_devd.conf
	${INSTALL_DATA}   ${WRKSRC}/automount.conf.sample ${PREFIX}/etc/automount.conf.sample
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
