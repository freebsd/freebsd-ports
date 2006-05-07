# New ports collection makefile for:	Senna
# Date created:		May 1 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	senna
PORTVERSION=	0.${SNAPDATE}
CATEGORIES=	textproc
MASTER_SITES=	http://dist.bsdlab.org/ \
		http://dev.razil.jp/archive/senna/
DISTNAME=	${PORTNAME}-${SNAPDATE}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Embeddable Fulltext Search Engine

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
INSTALLS_SHLIB=	YES
CONFIGURE_ARGS=	--with-sennahome=${SENNA_HOME}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}

SNAPDATE=	20060506
SENNA_HOME?=	/var/senna

.include <bsd.port.mk>
