# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	0.9.3
CATEGORIES=	net news www

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	PEAR class that provides an implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

LIB_FILES=	NNTP/Protocol.php NNTP/Header.php NNTP/Message.php

do-install:
	@${MKDIR} ${PEARDIR}/Net/NNTP
	@${CP} -p ${WRKSRC}/NNTP.php ${PEARDIR}/Net
.for FILE in ${LIB_FILES}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/Net/NNTP
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Net
.if !(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/news.php.net/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
