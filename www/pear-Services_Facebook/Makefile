# Ports collection makefile for:  pear-Services_Facebook
# Date created:			  13 April 2008
# Whom:				  Wen heping <wenheping@gmail.com>)
#
# $FreeBSD$
#

PORTNAME=	Services_Facebook
PORTVERSION=	0.1.1
CATEGORIES=	www pear

MAINTAINER=	wenheping@gmail.com
COMMENT=	PHP interface to Facebook's API

USE_PHP=	curl
CATEGORY=	Services

FILES=		Services/Facebook.php \
		Services/Facebook/Users.php Services/Facebook/Share.php \
		Services/Facebook/Profile.php \
		Services/Facebook/Photos.php \
		Services/Facebook/Pages.php \
		Services/Facebook/Notifications.php \
		Services/Facebook/MarketPlace.php \
		Services/Facebook/Groups.php \
		Services/Facebook/Friends.php \
		Services/Facebook/FQL.php Services/Facebook/Feed.php \
		Services/Facebook/FBML.php \
		Services/Facebook/Exception.php \
		Services/Facebook/Events.php \
		Services/Facebook/Common.php \
		Services/Facebook/Auth.php \
		Services/Facebook/Application.php \
		Services/Facebook/Admin.php \
		Services/Facebook/MarketPlace/Listing.php

TESTS=		010-users-isAppAdded.phpt \
		012-users-getInfo.phpt \
		014-users-getLoggedInUser.phpt \
		020-profile-setFBML.phpt \
		022-profile-getFBML.phpt \
		030-friends-areFriends.phpt \
		032-friends-get.phpt \
		034-friends-getAppUsers.phpt \
		040-fql-query.phpt \
		050-feed-publishStoryToUser.phpt \
		052-feed-publishActionOfUser.phpt \
		060-photos-createAlbum.phpt \
		062-photos-upload.phpt \
		080-application-getPublicInfoById.phpt \
		081-application-getPublicInfoByApiKey.phpt \
		082-application-getPublicInfoByCanvasName.phpt \
		090-admin-getNotificationsPerDay.phpt \
		091-admin-getRequestsPerDay.phpt \
		092-admin-getAppProperties.phpt \
		110-pages-isAdmin.phpt \
		111-pages-isFan.phpt \
		112-pages-isAppAdded.phpt \
		120-marketplace-createListing.phpt \
		121-marketplace-getCategories.phpt \
		122-marketplace-getSubCategory.phpt \
		123-marketplace-getListings.phpt \
		124-marketplace-removeListing.phpt \
		125-marketplace-search.phpt \
		test-image.jpg \
		tests-config.php.example

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
