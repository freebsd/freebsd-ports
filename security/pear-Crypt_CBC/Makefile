# Ports collection makefile for:  pear-Crypt_CBC
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_CBC
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class to emulate Perl's Crypt::CBC module

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/Crypt
	@${CP} -Rp ${WRKSRC}/CBC.php ${PEARDIR}/Crypt
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Crypt

.include <bsd.port.post.mk>
