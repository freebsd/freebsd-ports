# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	twig
PORTVERSION=	1.15.1
CATEGORIES=	www pear
MASTER_SITES=	http://pear.twig-project.org/get/
DISTNAME=	Twig-${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	The flexible, fast, and secure template engine for PHP

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig
RUN_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig

PEAR_CHANNEL=	twig
PEAR_AUTOINSTALL=	yes

USE_PHP=	ctype hash
WANT_PHP_CLI=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
