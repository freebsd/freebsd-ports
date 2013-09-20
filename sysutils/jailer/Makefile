# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	jailer
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://memberwebs.com/stef/freebsd/jails/jailer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manage FreeBSD jail startup, shutdown and console

GNU_CONFIGURE=	YES

MAN8=		injail.8 jailer.8

PLIST_FILES=	bin/injail \
		sbin/dmesg \
		sbin/halt \
		sbin/jailer \
		sbin/reboot

NO_STAGE=	yes
.include <bsd.port.mk>
