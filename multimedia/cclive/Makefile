# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.5.0
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Lightweight command line video extraction tool

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre

MAN1=		cclive.1

PLIST_FILES=	bin/cclive

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes
USE_GNOME=	pkgconfig
USE_ICONV=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		does not compiel
.endif

.include <bsd.port.post.mk>
