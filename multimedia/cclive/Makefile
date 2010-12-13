# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	kimelto@gmail.com
COMMENT=	Lightweight command line video extraction tool

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		quvi.3:${PORTSDIR}/multimedia/quvi

MAN1=		cclive.1

PLIST_FILES=	bin/cclive

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes
USE_GNOME=	pkgconfig

LICENSE=	GPLv3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
IGNORE=		does not compile
.endif

.include <bsd.port.post.mk>
