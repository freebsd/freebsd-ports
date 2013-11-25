# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Crypt_Blowfish
PORTVERSION=	1.1.0.r2
CATEGORIES=	security www pear
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/RC/}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class for blowfish encryption

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

PEAR_AUTOINSTALL=	yes

.if defined(WITH_PHP_MCRYPT)
USE_PHP=mcrypt
.endif

pre-fetch:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may set envirtonment variable WITH_PHP_MCRYPT to include"
	@${ECHO_CMD} "additional MCrypt PHP support"
	@${ECHO_CMD} ""

post-patch:
.for file in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" ${WRKSRC}/${file}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
