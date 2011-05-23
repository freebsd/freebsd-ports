# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.7.3.1
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/0.7 \
		GOOGLE_CODE

MAINTAINER=	kimelto@gmail.com
COMMENT=	Lightweight command line video extraction tool

LIB_DEPENDS=	boost_system.4:${PORTSDIR}/devel/boost-libs \
		curl.6:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		quvi.4:${PORTSDIR}/multimedia/quvi

MAN1=		cclive.1
PLIST_FILES=	bin/cclive

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes
USE_CMAKE=	yes
USE_GCC=	4.2+

LICENSE=	GPLv3

post-patch:
	@${REINPLACE_CMD} -e '/install / s|share/||' ${WRKSRC}/man1/CMakeLists.txt

.include <bsd.port.mk>
