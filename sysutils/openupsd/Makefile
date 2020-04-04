# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	openupsd
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://frmb.org/download/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	UPS daemon for some Belkin UPS's

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name= --bindir=${PREFIX}/sbin

PLIST_FILES=	sbin/openupsd etc/openupsd.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/openupsd.conf ${STAGEDIR}${PREFIX}/etc/openupsd.conf.sample

.include <bsd.port.mk>
