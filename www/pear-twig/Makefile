# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	twig
PORTVERSION=	1.15.1
CATEGORIES=	www pear
MASTER_SITES=	http://pear.twig-project.org/get/
DISTNAME=	Twig-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The flexible, fast, and secure template engine for PHP

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig
RUN_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig

USES=	pear
PEAR_CHANNEL=	twig

USE_PHP=	ctype hash
WANT_PHP_CLI=	yes

.include <bsd.port.mk>
