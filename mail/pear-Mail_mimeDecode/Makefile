# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	Mail_mimeDecode
PORTVERSION=	1.5.5
CATEGORIES=	mail www pear
DISTNAME=	Mail_mimeDecode-${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	Provides a class to decode mime messages

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime

LICENSE=	BSD

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
