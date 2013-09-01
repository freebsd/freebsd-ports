# Created by: Anton Yuzhaninov <citrin@citrin.ru>
# $FreeBSD$

PORTNAME=	Queue-Beanstalk
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	citrin@citrin.ru
COMMENT=	Client for beanstalkd, in-memory workqueue daemon

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Queue::Beanstalk.3
PLIST_FILES=	"%%SITE_PERL%%/Queue/Beanstalk.pm"
PLIST_FILES+=	"@dirrmtry %%SITE_PERL%%/Queue"

.include <bsd.port.mk>
