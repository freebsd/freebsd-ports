# New ports collection makefile for:	libdnet
# Date created:				15 April 2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	libdnet
PORTVERSION=	1.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	onatan@gmail.com
COMMENT=	A simple interface to low level networking routines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
PLIST_FILES+=	lib/${PYTHON_VERSION}/site-packages/dnet.so
.else
CONFIGURE_ARGS+=	--without-python
.endif

MAN3=	dnet.3
MAN8=	dnet.8

pre-everything::
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can add python support using WITH_PYTHON,"
	@${ECHO_MSG} "===>"
	@sleep 2
.endif

.include <bsd.port.mk>
