# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	0.2
CATEGORIES=	net news www

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	PEAR class that provides an implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
.if !exists(${PEARDIR}/Net)
	@${MKDIR} ${PEARDIR}/Net
.endif
	@${CP} -p ${WRKSRC}/NNTP.php ${PEARDIR}/Net
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Net

.include <bsd.port.post.mk>
