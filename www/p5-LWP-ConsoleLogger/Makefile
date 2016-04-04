# $FreeBSD$

PORTNAME=	LWP-ConsoleLogger
PORTVERSION=	0.000020
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for LWP tracing and debugging

LICENSE=	ART20

DEPRECATED=	Depends on expiring www/p5-HTTP-CookieMonster
EXPIRATION_DATE=	2016-04-15

RUN_DEPENDS=	\
	p5-Data-Printer>0:devel/p5-Data-Printer \
	p5-DateTime>0:devel/p5-DateTime \
	p5-HTML-Restrict>=0:www/p5-HTML-Restrict \
	p5-HTTP-Body>0:www/p5-HTTP-Body \
	p5-HTTP-CookieMonster>=0:www/p5-HTTP-CookieMonster \
	p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
	p5-Log-Dispatch>0:devel/p5-Log-Dispatch \
	p5-Moo>0:devel/p5-Moo \
	p5-MooX-StrictConstructor>0:devel/p5-MooX-StrictConstructor \
	p5-Parse-MIME>=0:mail/p5-Parse-MIME \
	p5-String-Trim>=0:textproc/p5-String-Trim \
	p5-Sub-Exporter>0:devel/p5-Sub-Exporter \
	p5-Term-Size-Any>0:devel/p5-Term-Size-Any \
	p5-Text-SimpleTable-AutoWidth>=0.09:textproc/p5-Text-SimpleTable-AutoWidth \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-Type-Tiny>0:devel/p5-Type-Tiny \
	p5-URI-Query>0:net/p5-URI-Query \
	p5-URI>=0:net/p5-URI \
	p5-XML-Simple>0:textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
