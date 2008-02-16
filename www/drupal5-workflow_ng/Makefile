# New ports collection makefile for:  drupal5-workflow_ng
# Date created:  11 February 2008
# Whom:          Jeremy Iverson <jeremy@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	workflow_ng
DISTVERSION=	5.x-1.6
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	jeremy@algenta.com
COMMENT=	Workflow-ng module for Drupal 5

DRUPAL5_MODULE=	yes
MODULE_DIRS=	cclinks states workflow_ng/icons workflow_ng/modules workflow_ng
MODULE_FILES=	cclinks/cclinks.info cclinks/cclinks.install cclinks/cclinks.module \
		cclinks/cclinks_action.inc cclinks/cclinks_admin.inc \
		states/API.txt states/states.info states/states.install states/states.module \
		states/states_views.inc states/states_workflow_ng.inc \
		workflow_ng/icons/action.png workflow_ng/icons/add.png \
		workflow_ng/icons/condition.png workflow_ng/icons/edit.png \
		workflow_ng/icons/indent.png \
		workflow_ng/modules/workflow_ng_comment.inc \
		workflow_ng/modules/workflow_ng_node.inc \
		workflow_ng/modules/workflow_ng_path.inc \
		workflow_ng/modules/workflow_ng_system.inc \
		workflow_ng/modules/workflow_ng_token.inc \
		workflow_ng/modules/workflow_ng_user.inc \
		workflow_ng/modules/workflow_ng_workflow_ng.inc \
		workflow_ng/workflow_ng.info workflow_ng/workflow_ng.install \
		workflow_ng/workflow_ng.module workflow_ng/workflow_ng_ui.css \
		workflow_ng/workflow_ng_ui.info workflow_ng/workflow_ng_ui.module
DOC_FILES=		LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
