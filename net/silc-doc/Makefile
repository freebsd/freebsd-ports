# New ports collection makefile for:	silc documentation
# Date created:				Mon Nov 12 21:35:24 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.7.5
CATEGORIES=	net security
MASTER_SITES=	http://www.silcnet.org/download/server/sources/ \
		ftp://ftp.silcnet.org/silc/server/sources/ \
		http://www.planetmirror.com/pub/silcnet/server/sources/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/server/sources/ \
		http://the.wiretapped.net/security/network-security/silc/server/sources/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/silc/server/sources/ \
		http://munitions.vipul.net/software/mirrors/silc/ \
		ftp://ftp.no.silcnet.org/pub/silc/server/sources/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PORTNAME}-server-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-docdir=${PREFIX}/share/doc/${PORTNAME}

.ifdef(NOPORTDOCS)
IGNORE=	this port only contains documentation
.endif

.include <bsd.port.mk>
