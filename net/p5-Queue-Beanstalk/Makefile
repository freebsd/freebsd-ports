# New ports collection makefile for:	p5-Queue-Beanstalk
# Date created:		2008-05-06
# Whom:			Anton Yuzhaninov <citrin@citrin.ru>
#
# $FreeBSD$
#

PORTNAME=	Queue-Beanstalk
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	citrin@citrin.ru
COMMENT=	Client for beanstalkd, in-memory workqueue daemon

PERL_CONFIGURE=	yes
PERL_MODBUILD=	yes

MAN3=	Queue::Beanstalk.3
PLIST_FILES=	"%%SITE_PERL%%/Queue/Beanstalk.pm"
PLIST_FILES+=	"@dirrmtry %%SITE_PERL%%/Queue"

.include <bsd.port.mk>
