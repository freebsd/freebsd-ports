# New ports collection makefile for:	p5-Kwiki-Cache
# Date created:				Feb 9 2006
# Whom:	      				Francisco Alves Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Kwiki-Cache
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	Kwiki Cache Plugin

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

DEPRECATED=		already bundled in www/p5-Kwiki (0.39 or latter)
EXPIRATION_DATE=	2007-07-28
IGNORE=		${DEPRECATED}

PERL_CONFIGURE=	yes

MAN3=		Kwiki::Cache.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
