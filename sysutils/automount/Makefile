# New ports collection Makefile for: automount
# Date created:                      04 March 2012
# Whom:                              Slawomir Wojciech Wojtczak <vermaden@interia.pl>
#
# $FreeBSD$
#

PORTNAME=     automount
PORTVERSION=  1.3.1
CATEGORIES=   sysutils
MASTER_SITES= https://raw.github.com/vermaden/automount/master/

MAINTAINER=   vermaden@interia.pl
COMMENT=      FreeBSD's devd(8) based automount solution

LICENSE=      BSD

PLIST_FILES=  sbin/automount etc/devd/automount_devd.conf etc/automount.conf.sample

NO_BUILD=     yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/automount             ${PREFIX}/sbin
	${INSTALL_DATA}   ${WRKSRC}/automount_devd.conf   ${PREFIX}/etc/devd/automount_devd.conf
	${INSTALL_DATA}   ${WRKSRC}/automount.conf.sample ${PREFIX}/etc/automount.conf.sample
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
