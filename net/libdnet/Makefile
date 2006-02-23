# New ports collection makefile for:	libdnet
# Date created:				15 April 2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	libdnet
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif

MAINTAINER=	onatan@gmail.com
COMMENT?=	A simple interface to low level networking routines

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

SLAVE_DIRS=	net/py-libdnet

.if defined(BUILD_PYTHON_MODULE)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}/python
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dnet.so
PLIST_SUB+=	MASTER="@comment "
.else
CONFIGURE_ARGS+=	--without-python
INSTALLS_SHLIB=	yes
PLIST_SUB+=	MASTER=""

MAN3=	dnet.3
MAN8=	dnet.8
.endif

pre-everything::
.if !defined(BUILD_PYTHON_MODULE)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can add python support with the port ${SLAVE_DIRS}."
	@${ECHO_MSG} "===>"
	@sleep 2
.endif

.if defined(BUILD_PYTHON_MODULE) && defined(MAINTAINER_MODE)
test:	install
	${PYTHON_CMD} ${INSTALL_WRKSRC}/test.py
.endif

.include <bsd.port.mk>
