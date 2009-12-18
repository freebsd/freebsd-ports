# Ports collection makefile for:  pear-Services_Facebook
# Date created:			  13 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>)
#
# $FreeBSD$
#

PORTNAME=	Services_Facebook
PORTVERSION=	0.2.9
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Facebook's API

BUILD_DEPENDS=	${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
RUN_DEPENDS=	${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate

USE_PHP=	curl
CATEGORY=	Services

FILES=		Services/Facebook.php \
		Services/Facebook/Users.php \
		Services/Facebook/Share.php \
		Services/Facebook/Profile.php \
		Services/Facebook/Photos.php \
		Services/Facebook/Pages.php \
		Services/Facebook/Notifications.php \
		Services/Facebook/MarketPlace.php \
		Services/Facebook/Groups.php \
		Services/Facebook/Friends.php \
		Services/Facebook/FQL.php \
		Services/Facebook/Feed.php \
		Services/Facebook/FBML.php \
		Services/Facebook/Exception.php \
		Services/Facebook/Events.php \
		Services/Facebook/Data.php \
		Services/Facebook/Common.php \
		Services/Facebook/Connect.php \
		Services/Facebook/Batch.php \
		Services/Facebook/Auth.php \
		Services/Facebook/Application.php \
		Services/Facebook/Admin.php \
		Services/Facebook/MarketPlace/Listing.php

TESTS=		AllTests.php Services/AllTests.php \
		Services/Facebook/AdminTest.php Services/Facebook/AllTests.php \
		Services/Facebook/ApplicationTest.php Services/Facebook/AuthTest.php \
		Services/Facebook/BatchTest.php Services/Facebook/CommonTest.php \
		Services/Facebook/ConnectTest.php Services/Facebook/EventsTest.php \
		Services/Facebook/FBMLTest.php Services/Facebook/FQLTest.php \
		Services/Facebook/FeedTest.php Services/Facebook/FriendsTest.php \
		Services/Facebook/GroupsTest.php Services/Facebook/MarketPlaceTest.php \
		Services/Facebook/NotificationsTest.php Services/Facebook/PagesTest.php \
		Services/Facebook/PhotosTest.php Services/Facebook/ProfileTest.php \
		Services/Facebook/ShareTest.php Services/Facebook/UnitTestCommon.php \
		Services/Facebook/UsersTest.php Services/Facebook/skel.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
