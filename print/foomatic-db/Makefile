# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	db
PORTVERSION=	20090530
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,$,acm/foomatic/,} \
		${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	foomatic-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${FOOMATICVER}-${PORTVERSION}
DIST_SUBDIR=	foomatic

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Foomatic database

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		curl:${PORTSDIR}/ftp/curl

PROJECTHOST=	bsdistfiles
USE_GMAKE=	yes
USES=		perl5
USE_AUTOTOOLS=	automake:env autoconf

GNU_CONFIGURE=	yes

FOOMATICVER=	4.0
WRKSRC=	${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

.include <bsd.port.mk>
