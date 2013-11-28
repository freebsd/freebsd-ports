# Created by: Alex Miller (<asm@asm.kiev.ua>)
# $FreeBSD$

PORTNAME=	HTTP_Upload
PORTVERSION=	0.9.1
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Easy and secure management of files submitted via HTML Forms

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
