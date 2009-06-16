# New ports collection makefile for:  drupal6-token
# Date created:  11 February 2008
# Whom:          Jeremy Iverson <jeremy@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	token
DISTVERSION=	6.x-1.12
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Token module for Drupal

DRUPAL6_MODULE=	yes
MODULE_FILES=	translations/token.pot translations/da.po translations/de.po \
		translations/es.po translations/hu.po translations/ja.po \
		translations/pl.po translations/sk.po translations/uk-ua.po \
		translations/uk.po token.info token.install token.module \
		token.rules.inc token.test tokenSTARTER.info \
		tokenSTARTER.module token_actions.info token_actions.module \
		token_comment.inc token_node.inc token_taxonomy.inc \
		token_user.inc
MODULE_DIRS=	translations

DOC_FILES=	API.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
