# New ports collection makefile for:	qbrew
# Date created:				22 September 2000
# Whom:					David Johnson <david@usermode.org>
#
# $FreeBSD$
#

PORTNAME=	qbrew
PORTVERSION=	0.3.1
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	david@usermode.org

GNU_CONFIGURE=	yes

QT_VERSION?=	3

.if ${QT_VERSION} == "3"
USE_QT_VER=	3
CONFIGURE_ARGS+=--enable-threads
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Configuring for use with Qt 3.x libraries."
	@${ECHO_MSG} "If you want to compile with Qt 2.x  support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make QT_VERSION=2\""
	@${ECHO_MSG}
.else
USE_QT_VER=	2
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Configuring for use with Qt 2.x libraries."
	@${ECHO_MSG} "If you want to compile with Qt 3.x  support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make QT_VERSION=3\""
	@${ECHO_MSG}
.endif

post-install:
	strip ${PREFIX}/bin/qbrew

.include <bsd.port.mk>
