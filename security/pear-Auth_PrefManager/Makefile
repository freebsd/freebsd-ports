# Ports collection makefile for:  pear-Auth_PrefManager
# Date created:			  05 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Auth_PrefManager
PORTVERSION=	1.2.0
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR preferences management class

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Auth
FILES=		PrefManager.php
DOCS=		PM_Example.php

TESTS=		deleteDefaultPref/database-error-pear.phpt deleteDefaultPref/database-error.phpt \
		deleteDefaultPref/pref-exists-default-exists.phpt  \
		deleteDefaultPref/pref-exists-default-notexist.phpt \
		deleteDefaultPref/pref-notexist-default-exist.phpt \
		deleteDefaultPref/pref-notexist-default-notexist.phpt \
		deletePref/database-error-pear.phpt deletePref/database-error.phpt \
		deletePref/pref-exists-default-exists.phpt \
		deletePref/pref-exists-default-notexist.phpt \
		deletePref/pref-notexist-default-exist.phpt  \
		deletePref/pref-notexist-default-notexist.phpt \
		getDefaultPref/database-error-pear.phpt getDefaultPref/database-error.phpt \
		getDefaultPref/default-exists.phpt getDefaultPref/default-notexist.phpt \
		getPref/database-error-pear.phpt getPref/database-error.phpt \
		getPref/pref-exists-default-exists.phpt getPref/pref-exists-default-notexist.phpt \
		getPref/pref-notexist-default-exist.phpt getPref/pref-notexist-default-notexist.phpt \
		setDefaultPref/database-error-pear.phpt setDefaultPref/database-error.phpt \
		setDefaultPref/pref-exists-default-exists.phpt \
		setDefaultPref/pref-exists-default-notexist.phpt \
		setDefaultPref/pref-notexist-default-exists.phpt \
		setDefaultPref/pref-notexist-default-notexist.phpt \
		setPref/database-error-pear.phpt setPref/database-error.phpt \
		setPref/pref-exists-default-exists.phpt setPref/pref-notexist-default-exists.phpt \
		setup.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
