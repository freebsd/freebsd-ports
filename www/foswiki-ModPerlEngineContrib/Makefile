# New ports collection makefile for:	foswiki-ModPerlEngineContrib
# Date created:		26 Feb 2011
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ModPerlEngineContrib
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Permits Foswiki to be executed under mod_perl

BUILD_DEPENDS=	foswiki>=0:/usr/ports/www/foswiki
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=2.0.0:${PORTSDIR}/www/mod_perl2 \
		p5-libapreq2>=2.0:${PORTSDIR}/www/p5-libapreq2

SVNREV=		8600

USE_APACHE=	2.2+

BROKEN=		conflicting dependencies

.include "${.CURDIR}/../foswiki/bsd.foswiki.mk"
.include <bsd.port.mk>
