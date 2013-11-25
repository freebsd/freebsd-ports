# Created by: Shinsuke Matsui (<smatsui@karashi.org>)
# $FreeBSD$

PORTNAME=	Net_UserAgent_Mobile
PORTVERSION=	1.0.0
CATEGORIES=	net www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}RC1

MAINTAINER=	smatsui@karashi.org
COMMENT=	PEAR class that parses HTTP mobile user agent string

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	pcre
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
