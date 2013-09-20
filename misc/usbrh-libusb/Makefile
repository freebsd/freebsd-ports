# Created by: sanpei@FreeBSD.org
# $FreeBSD$

PORTNAME=	usbrh-libusb
PORTVERSION=	0.05
CATEGORIES=	misc
MASTER_SITES=	http://www.dd.iij4u.or.jp/~briareos/soft/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sanpei
DISTNAME=	usbrh-${PORTVERSION}

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Yet another reads temperatures and humidity from a Strawberry Linux USB-RH

PLIST_FILES=	bin/usbrh

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800097
BROKEN=         does not build
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/usbrh ${PREFIX}/bin/usbrh

.include <bsd.port.post.mk>
