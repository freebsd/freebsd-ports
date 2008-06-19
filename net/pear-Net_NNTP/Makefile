# Ports collection makefile for:	pear-Net_NNTP
# Date created:				07 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	Net_NNTP
PORTVERSION=	1.4.0
PORTEPOCH=	1
CATEGORIES=	net news pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR implementation of the NNTP protocol

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		NNTP/Client.php NNTP/Header.php NNTP/Message.php \
		NNTP/Protocol/Client.php NNTP/Protocol/Responsecode.php

EXAMPLES=	demo/article.php demo/common.inc.php demo/config.inc.php demo/footer.inc.php \
		demo/group.php demo/groups.php demo/header.inc.php demo/index.php demo/style.css \
		phpdoc/authenticate.php phpdoc/connect.php phpdoc/constructor.php phpdoc/getDescriptions.php \
		phpdoc/getGroups.php phpdoc/getOverview.php phpdoc/selectArticle.php \
		phpdoc/selectGroup.php phpdoc/selectNextArticle.php phpdoc/selectPreviousArticle.php

_EXAMPLESDIR=	docs/examples/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
