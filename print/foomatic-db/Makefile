# New ports collection makefile for:	foomatic-db
# Date created:			01 March 2003
# Whom:				Dima Dorfman <dima@unixfreak.org>
#
# $FreeBSD$
#

PORTNAME=	db
PORTVERSION=	20090530
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,$,acm/foomatic/,} \
		${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	foomatic-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${FOOMATICVER}-${PORTVERSION}
DIST_SUBDIR=	foomatic

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Foomatic database

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		curl.5:${PORTSDIR}/ftp/curl

PROJECTHOST=	bsdistfiles
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:262

GNU_CONFIGURE=	yes

FOOMATICVER=	4.0
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

.include <bsd.port.mk>
