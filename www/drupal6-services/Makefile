# New ports collection makefile for:	drupal6-services
# Date created:				18 Mar 2010
# Whom:					whitekid@gmail.com
#
# $FreeBSD$
#

PORTNAME=	services
DISTVERSION=	6.x-2.2
CATEGORIES=	www

MAINTAINER=	whitekid@gmail.com
COMMENT=	Provide an API for creating drupal web services.

DRUPAL6_MODULE=	yes
MODULE_DIRS=	auth/services_keyauth auth servers/xmlrpc_server servers \
		services/comment_service services/file_service \
		services/menu_service services/node_service \
		services/search_service services/system_service \
		services/taxonomy_service services/user_service \
		services/views_service services

MODULE_FILES=	auth/services_keyauth/services_keyauth.admin.inc \
		auth/services_keyauth/services_keyauth.inc \
		auth/services_keyauth/services_keyauth.info \
		auth/services_keyauth/services_keyauth.install \
		auth/services_keyauth/services_keyauth.module \
		servers/xmlrpc_server/xmlrpc_server.info \
		servers/xmlrpc_server/xmlrpc_server.module \
		services/comment_service/comment_service.inc \
		services/comment_service/comment_service.info \
		services/comment_service/comment_service.module \
		services/file_service/file_service.inc \
		services/file_service/file_service.info \
		services/file_service/file_service.module \
		services/menu_service/menu_service.inc \
		services/menu_service/menu_service.info \
		services/menu_service/menu_service.module \
		services/node_service/node_resource.inc \
		services/node_service/node_resource.info \
		services/node_service/node_resource.models.inc \
		services/node_service/node_resource.module \
		services/node_service/node_service.inc \
		services/node_service/node_service.info \
		services/node_service/node_service.module \
		services/search_service/search_service.inc \
		services/search_service/search_service.info \
		services/search_service/search_service.module \
		services/search_service/search_service_admin.inc \
		services/system_service/system_service.inc \
		services/system_service/system_service.info \
		services/system_service/system_service.module \
		services/taxonomy_service/taxonomy_service.inc \
		services/taxonomy_service/taxonomy_service.info \
		services/taxonomy_service/taxonomy_service.module \
		services/user_service/user_service.inc \
		services/user_service/user_service.info \
		services/user_service/user_service.module \
		services/views_service/views_service.inc \
		services/views_service/views_service.info \
		services/views_service/views_service.module services.css \
		services.info services.install services.module \
		services.resource-translation.inc services_admin_browse.inc

DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
