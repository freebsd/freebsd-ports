# New ports collection makefile for:	kbedic
# Date created:			17 January 2002
# Whom:				Angel Todorov <todorov_bg@gmx.net>
#
# $FreeBSD$
#

PORTNAME?=	kbedic
PORTVERSION?=	2.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://kbedic.search.bg/download/
MASTER_SITE_SUBDIR=kbedic
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	todorov@freebsd-bg.org
COMMENT=	An English-to-Bulgarian and Bulgarian-to-English dictionary

RUN_DEPENDS=	${DICT_DIR}/${DICT_CHECK}:${PORTSDIR}/textproc/bedic-data

DICT_CHECK?=	buleng.dat
DICT_DIR?=	${LOCALBASE}/share

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DICT_DIR}

.if !defined(CONSOLE_VER)
USE_QT_VER=	2
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--with-x
EXTRA_PATCHES+=	${FILESDIR}/src::win.cpp.patch
.else
PLIST=		${PKGDIR}/pkg-plist.console
EXTRA_PATCHES+=	${FILESDIR}/src::cbedic.cpp.patch
.endif

.include <bsd.port.pre.mk>

pre-fetch:
		@${ECHO_MSG} "	--- Dictionaries setup information ---"
		@${ECHO_MSG} "This port uses dictionaries provided by the textproc/bedic-data port."
		@${ECHO_MSG} "You may set the following variables to help the system locate"
		@${ECHO_MSG} "the dictionaries that you have installed:"
		@${ECHO_MSG} "	DICT_DIR	the directory where the dictionaries"
		@${ECHO_MSG} "			are located; currently ${DICT_DIR}"
		@${ECHO_MSG} "	DICT_CHECK	a filename of an installed dictionary"
		@${ECHO_MSG} "			to check for; currently ${DICT_CHECK}"
		@${ECHO_MSG} "If no dictionaries are installed yet, you may set the DICTIONARIES variable"
		@${ECHO_MSG} "to the names of the dictionaries that the textproc/bedic-data port"
		@${ECHO_MSG} "will install; refer to that port for more information."

.include <bsd.port.post.mk>
