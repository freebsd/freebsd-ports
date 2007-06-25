# Ports collection makefile for:  pear-Services_Digg
# Date created:			  17 May 2007
# Whom:				  Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Digg
PORTVERSION=	0.1.1
CATEGORIES=	www pear

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	PHP interface to Digg's API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	curl

CATEGORY=	Services
FILES=		Digg.php Digg/Comments.php Digg/Comment.php Digg/Common.php \
		Digg/Errors.php Digg/Exception.php Digg/Proxy.php Digg/Response.php \
		Digg/Stories.php Digg/Story.php Digg/Topics.php Digg/User.php \
		Digg/Users.php Digg/Response/Common.php Digg/Response/php.php \
		Digg/Response/xml.php

TESTS=		000-services-digg-factory.phpt 001-errors-getAll.phpt \
		003-errors-getErrorByCode.phpt 005-topics-getAll.phpt \
		010-user-submissions.phpt 011-user-isFriend.phpt \
		012-user-isFan.phpt 013-user-comments.phpt \
		014-user-diggs.phpt 020-users-getUserByName.phpt \
		030-stories-getStoryById.phpt 031-stories-getContainer.phpt \
		032-stories-getContainerPopular.phpt \
		032-stories-getContainerUpcoming.phpt \
		033-stories-getStoriesById.phpt 034-stories-comments.phpt \
		034-stories-diggs.phpt 034-stories-popular.phpt \
		035-stories-getAll.phpt 035-stories-getStoriesComments.phpt \
		035-stories-getStoriesDiggs.phpt 036-stories-getStoryByTitle.phpt \
		040-story-comments.phpt 041-story-getCommentById.phpt \
		050-comments.phpt 060-comment-replies.phpt \
		070-proxy-get.phpt 071-proxy-post.phpt \
		200-diggapiuser-isFriend.phpt 201-diggapistories-iteration.phpt \
		tests-config.php

post-extract:
	${MV} ${WRKSRC}/Services/Digg.php ${WRKSRC}
	${MV} ${WRKSRC}/Services/Digg ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
