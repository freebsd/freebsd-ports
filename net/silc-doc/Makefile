# New ports collection makefile for:	silc documentation
# Date created:				Mon Nov 12 21:35:24 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.6.4
CATEGORIES=	net security
MASTER_SITES=	http://www.silcnet.org/download/ \
		ftp://ftp.silcnet.org/pub/silc/ \
		http://ftp.silcnet.org/ \
		http://munitions.vipul.net/software/mirrors/silc/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/silc/ \
		http://www.au.silcnet.org/download/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/ \
		http://www.planetmirror.com/pub/silcnet/ \
		http://the.wiretapped.net/security/network-security/silc/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/silc/ \
		http://www.no.silcnet.org/download/ \
		ftp://ftp.no.silcnet.org/pub/silc/
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
