# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Mail-Cache
PORTVERSION=	0.1.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Caches mail information

BUILD_DEPENDS=	p5-File-BaseDir>=0:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-Email-Simple>=0:${PORTSDIR}/mail/p5-Email-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::Cache.3

NO_STAGE=	yes
.include <bsd.port.mk>
