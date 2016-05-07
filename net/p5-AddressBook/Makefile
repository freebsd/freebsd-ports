# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AddressBook
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DLEIGH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module providing an LDAP addressbook interface


BUILD_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-XML-DOM>=0:textproc/p5-XML-DOM
RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-XML-DOM>=0:textproc/p5-XML-DOM

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
