# Ports collection makefile for:  pear-Services_Twitter
# Date created:			  2008-11-06
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Twitter
PORTVERSION=	0.6.3
CATEGORIES=	net www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Twitter's API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	json simplexml mbstring

PEAR_CATSRC=	yes
FILES=		Services/Twitter.php Services/Twitter/Exception.php
DATA=		api.rng api.xml
TESTS=		000-statuses-public_timeline.phpt \
		010-statuses-friends_timeline.phpt \
		020-statuses-user_timeline.phpt \
		030-statuses-show.phpt \
		040-statuses-update-destroy.phpt \
		060-statuses-friends.phpt \
		070-statuses-followers.phpt \
		100-users-show.phpt \
		200-direct_messages.phpt \
		210-direct_messages-sent.phpt \
		220-direct_messages-new-destroy.phpt \
		300-friendships-create-destroy.phpt \
		310-friendships-exists.phpt \
		400-account-verify_credentials.phpt \
		410-account-end_session.phpt \
		430-account-update_delivery_device.phpt \
		440-account-rate_limit_status.phpt \
		450-account-update_profile_colors.phpt \
		460-account-update_profile_image.phpt \
		470-account-update_profile_background_image.phpt \
		480-account-update_profile.phpt \
		500-favorites.phpt \
		510-favorites-create-destroy.phpt \
		600-notifications-follow-leave.phpt \
		700-blocks-create-destroy.phpt \
		800-help-test.phpt \
		810-search.phpt \
		820-trends-daily.phpt \
		830-trends-weekly.phpt \
		900-exceptions.phpt \
		910-options.phpt \
		920-utf8.phpt \
		930-validation.phpt \
		AllTests.php \
		data/account/end_session.dat \
		data/account/rate_limit_status.dat \
		data/account/update_delivery_device.dat \
		data/account/update_location.dat \
		data/account/update_profile.dat \
		data/account/update_profile_background_image.dat \
		data/account/update_profile_colors.dat \
		data/account/update_profile_image.dat \
		data/account/verify_credentials.dat \
		data/background.jpg \
		data/blocks/create_destroy.dat \
		data/direct_messages/destroy_new.dat \
		data/direct_messages/direct_messages.dat \
		data/direct_messages/sent.dat \
		data/favorites/create.dat \
		data/favorites/destroy.dat \
		data/favorites/favorites.dat \
		data/friendships/create_destroy.dat \
		data/friendships/exists1.dat \
		data/friendships/exists2.dat \
		data/friendships/exists3.dat \
		data/friendships/exists4.dat \
		data/help/downtime_schedule.dat \
		data/help/test.dat \
		data/notifications/follow_leave.dat \
		data/options.dat \
		data/profile.png \
		data/search/search.dat \
		data/statuses/destroy.dat \
		data/statuses/followers.dat \
		data/statuses/friends.dat \
		data/statuses/friends_timeline.dat \
		data/statuses/public_timeline.dat \
		data/statuses/replies.dat \
		data/statuses/show.dat \
		data/statuses/update.dat \
		data/statuses/user_timeline.dat \
		data/trends/daily.dat \
		data/trends/weekly.dat \
		data/users/show.dat \
		data/utf8.dat \
		setup.php \
		tests-config.php.example

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
