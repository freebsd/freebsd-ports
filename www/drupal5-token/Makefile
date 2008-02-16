# New ports collection makefile for:  drupal5-token
# Date created:  11 February 2008
# Whom:          Jeremy Iverson <jeremy@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	token
DISTVERSION=	5.x-1.10
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	jeremy@algenta.com
COMMENT=	Token module for Drupal 5

DRUPAL5_MODULE=	yes
MODULE_FILES=	token_cck.inc token_comment.inc token_node.inc \
		token_taxonomy.inc token_user.inc token.inc \
		token.info token.install token.module
DOC_FILES=	API.txt CHANGELOG.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
