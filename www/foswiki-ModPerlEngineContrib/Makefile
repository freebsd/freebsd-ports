# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ModPerlEngineContrib
MASTER_SITES=	http://protey.ru/freebsd/distfiles/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Permits Foswiki to be executed under mod_perl

RUN_DEPENDS=	foswiki>=0:${PORTSDIR}/www/foswiki \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=2.0.0:${PORTSDIR}/www/mod_perl2 \
		p5-libapreq2>=2.0:${PORTSDIR}/www/p5-libapreq2

SVNREV=		8600

USE_APACHE_RUN=	22+

.include "${.CURDIR}/../foswiki/bsd.foswiki.mk"
.include <bsd.port.mk>
