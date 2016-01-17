# Created by: Jeremy Iverson <jeremy@algenta.com>
# $FreeBSD$

PORTNAME=	token
DISTVERSION=	6.x-1.12
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Token module for Drupal

USES=		drupal:6,module
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
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
