# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Crypt_RSA
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class allows you to use two-key strong cryptography

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

OPTIONS_DEFINE=	BCMATH GMP
BCMATH_DESC=	PHP BCMath extension support
GMP_DESC=	PHP GMP extension support

LATEST_LINK=	pear-${PORTNAME}

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.for opt in BCMATH GMP
.    if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:L}
.    endif
.endfor

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
