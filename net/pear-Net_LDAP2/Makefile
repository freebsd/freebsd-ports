# Ports collection makefile for:  pear-Net_LDAP
# Date created:			  26 June 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_LDAP
PORTVERSION=	0.7.1
CATEGORIES=	net pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	OO interface for searching and manipulating LDAP-entries

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	ldap
CATEGORY=	Net
FILES=		LDAP.php \
		LDAP/Entry.php LDAP/RootDSE.php LDAP/Schema.php \
		LDAP/Search.php LDAP/Util.php
DOCS=		README.txt RootDSE.txt STATUS Schema.txt utf8.txt
_DOCSDIR=	./doc
TESTS=		tests.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
