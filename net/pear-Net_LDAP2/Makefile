# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Net_LDAP2
PORTVERSION=	2.0.12
PORTEPOCH=	1
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OO interface for searching and manipulating LDAP-entries

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	ldap

PEAR_AUTOINSTALL=yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
