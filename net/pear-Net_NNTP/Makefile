# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	0.10.1
CATEGORIES=	net news www pear

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	PEAR class that provides an implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

LIB_FILES=	NNTP/Realtime.php NNTP/Protocol.php NNTP/Header.php NNTP/Message.php
PORTDOCS=	README

.if defined(NOPORTEXAMPLES)
PLIST_SUB+=		PORTEXAMPLES="@comment "
.else
PLIST_SUB+=		PORTEXAMPLES=""
.endif

do-install:
	@${MKDIR} ${PEARDIR}/Net/NNTP
	@${CP} -p ${WRKSRC}/NNTP.php ${PEARDIR}/Net
.for FILE in ${LIB_FILES}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/Net/NNTP
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Net
.if !(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/news.php.net/*.php ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/news.php.net/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
