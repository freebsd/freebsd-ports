# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	openupsd
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://frmb.org/download/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	A UPS daemon for some Belkin UPS's

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name= --bindir=${PREFIX}/sbin

PLIST_FILES=	sbin/openupsd etc/openupsd.conf.sample

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/openupsd.conf ${PREFIX}/etc/openupsd.conf.sample

.include <bsd.port.mk>
