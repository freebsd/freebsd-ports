# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	twig
PORTVERSION=	1.22.3
CATEGORIES=	www pear
MASTER_SITES=	http://pear.twig-project.org/get/
DISTNAME=	Twig-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible, fast, and secure template engine for PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig
RUN_DEPENDS=	${PEARDIR}/.channels/pear.twig-project.org.reg:${PORTSDIR}/devel/pear-channel-twig

USES=		pear
PEAR_CHANNEL=	twig
NO_ARCH=	yes

USE_PHP=	ctype hash
WANT_PHP_CLI=	yes

.include <bsd.port.mk>
