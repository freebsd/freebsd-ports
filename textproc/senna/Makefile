# New ports collection makefile for:	Senna
# Date created:		May 1 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	senna
PORTVERSION=	0.${SNAPDATE}
CATEGORIES=	textproc
MASTER_SITES=	http://dev.razil.jp/archive/senna/
DISTNAME=	${PORTNAME}-${SNAPDATE}-svn

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Embeddable Fulltext Search Engine

LIB_DEPENDS=	mecab-razil:${PORTSDIR}/japanese/mecab-razil

USE_LIBTOOL_VER=15
USE_AUTOCONF_VER=	259
USE_AUTOMAKE_VER=	14
USE_GMAKE=	YES
INSTALLS_SHLIB=	YES
CONFIGURE_ARGS=	--with-sennahome=${SENNA_HOME}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
WRKSRC=		${WRKDIR}/${PORTNAME}

SNAPDATE=	20050827
SENNA_HOME?=	/var/senna

post-patch:
	cd ${WRKSRC}; \
	${TOUCH} -r configure.ac.orig configure.ac

.include <bsd.port.mk>
