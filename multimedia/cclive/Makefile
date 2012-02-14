# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.7.8
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/0.7 \
		GOOGLE_CODE

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Lightweight command line video extraction tool

LICENSE=	GPLv3

LIB_DEPENDS=	boost_system.4:${PORTSDIR}/devel/boost-libs \
		curl.6:${PORTSDIR}/ftp/curl \
		pcre.1:${PORTSDIR}/devel/pcre \
		quvi.7:${PORTSDIR}/multimedia/libquvi

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_XZ=		yes

MAN1=		cclive.1
PLIST_FILES=	bin/cclive

.include <bsd.port.mk>
