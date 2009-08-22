# Ports collection makefile for:  pear-Services_Twitter
# Date created:			  2008-11-06
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Twitter
PORTVERSION=	0.2.1
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Twitter's API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	curl

CATEGORY=	Net
FILES=		Services/Twitter.php Services/Twitter/Account.php \
		Services/Twitter/Common.php \
		Services/Twitter/DirectMessages.php \
		Services/Twitter/Exception.php \
		Services/Twitter/Favorites.php \
		Services/Twitter/Friendships.php \
		Services/Twitter/Notifications.php \
		Services/Twitter/Search.php \
		Services/Twitter/Statuses.php \
		Services/Twitter/Users.php
TESTS=		005-services-twitter-statuses-public-timeline.phpt \
		006-services-twitter-statuses-friends-timeline.phpt \
		007-services-twitter-statuses-user-timeline.phpt \
		010-services-twitter-statuses-show.phpt \
		015-services-twitter-statuses-replies.phpt \
		020-services-twitter-statuses-update.phpt \
		025-services-twitter-statuses-destroy.phpt \
		026-services-twitter-statuses-friends.phpt \
		027-services-twitter-statuses-followers.phpt \
		028-services-twitter-statuses-featured.phpt \
		030-services-twitter-exception.phpt \
		100-services-twitter-users-show.phpt \
		200-services-twitter-direct-messages.phpt \
		205-services-twitter-direct-messages-sent.phpt \
		210-services-twitter-direct-messages-new.phpt \
		215-services-twitter-direct-messages-destroy.phpt \
		300-services-twitter-friendships-create.phpt \
		305-services-twitter-friendships-destroy.phpt \
		400-services-twitter-account-verify-credentials.phpt \
		405-services-twitter-account-end-session.phpt \
		410-services-twitter-account-archive.phpt \
		500-services-twitter-favorites.phpt \
		505-services-twitter-favorites-create.phpt \
		510-services-twitter-favorites-destroy.phpt \
		600-services-twitter-notifications-leave.phpt \
		605-services-twitter-notifications-follow.phpt \
		tests-config.php.example

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
