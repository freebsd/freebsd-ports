# New ports collection makefile for:	linux-seamonkey-devel
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	seamonkey
PORTVERSION=	2.0.a${SNAPDATE:S/-/./g}
DISTVERSION=	2.0a1pre
DISTVERSIONSUFFIX=	.en-US.linux-i686
CATEGORIES=	www
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/%SUBDIR%/ \
		http://ftp.belnet.be/packages/mozilla/%SUBDIR%/ \
		ftp://ftp.belnet.be/packages/mozilla/%SUBDIR%/ \
		CENKES/myports/${DIST_SUBDIR}
MASTER_SITE_SUBDIR=	${PORTNAME}/nightly/${SNAPDATE}-01-trunk
PKGNAMESUFFIX=		-devel
DIST_SUBDIR=		${PORTNAME}-${SNAPDATE}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

SNAPDATE=	2007-06-26
USE_BZIP2=	yes

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
