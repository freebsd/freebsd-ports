# Ports collection makefile for:  pear-Net_Socket
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_Socket
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Network Socket Interface

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/Net
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}/Net
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Net

.include <bsd.port.post.mk>
