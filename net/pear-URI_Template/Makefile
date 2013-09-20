# Created by: wenheping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	URI_Template
PORTVERSION=	0.3.3
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Parser for URI Templates

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
