# New ports collection makefile for:	silc documentation
# Date created:				Mon Nov 12 21:35:24 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	silc
PORTVERSION=	0.9.10.1
CATEGORIES=	net security
MASTER_SITES=	http://www.silcnet.org/download/%SUBDIR%/ \
		http://ftp.silcnet.org/%SUBDIR%/ \
		http://www.planetmirror.com/pub/silcnet/%SUBDIR%/ \
		http://www.nic.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		http://www.fi.silcnet.org/download/%SUBDIR%/ \
		http://munitions.vipul.net/software/mirrors/silc/%SUBDIR%/ \
		http://www.pl.silcnet.org/download/%SUBDIR%/ \
		http://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.au.silcnet.org/pub/silcnet/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.silcnet.org/silc/%SUBDIR%/ \
		ftp://ftp.pl.silcnet.org/pub/silc/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/silc/%SUBDIR%/ \
		ftp://ftp.uk.silcnet.org/pub/silc/%SUBDIR%/
MASTER_SITE_SUBDIR=	server/sources
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
