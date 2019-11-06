# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	GRNOC-Config
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	SF/routerproxy/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Module to allow everyone to access config files

BROKEN=		unfetchable

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-LibXML>=2:textproc/p5-XML-LibXML \
		p5-XML-XPath>=1:textproc/p5-XML-XPath \
		p5-XML-Simple>=2:textproc/p5-XML-Simple

USE_PERL5=	configure
USES=		perl5

PLIST_FILES=	%%SITE_PERL%%/GRNOC/Config.pm \
		%%PERL5_MAN3%%/GRNOC::Config.3.gz

.include <bsd.port.mk>
