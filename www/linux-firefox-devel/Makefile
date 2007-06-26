# New ports collection makefile for:	linux-firefox-devel
# Date created:		8 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	3.0.a${SNAPDATE:S/-/./g}
DISTVERSION=	3.0a6pre
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www
MASTER_SITES=   http://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
		http://ftp.belnet.be/packages/mozilla/%SUBDIR%/ \
		ftp://ftp.belnet.be/packages/mozilla/%SUBDIR%/ \
		CENKES/myports/${DIST_SUBDIR}
MASTER_SITE_SUBDIR=	${PORTNAME}/nightly/${SNAPDATE}-04-trunk
PKGNAMESUFFIX=		-devel
DIST_SUBDIR=		${PORTNAME}-${SNAPDATE}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

SNAPDATE=	2007-06-26
USE_BZIP2=	yes

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
