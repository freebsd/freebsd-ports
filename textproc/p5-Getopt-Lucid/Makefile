# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Getopt-Lucid
PORTVERSION=	1.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Getopt::Lucid - Clear, readable syntax for command line processing

BUILD_DEPENDS=	p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Exception-Class-TryCatch>=1.10:${PORTSDIR}/devel/p5-Exception-Class-TryCatch \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	p5-Exception-Class>=1.23:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Storable>=2.16:${PORTSDIR}/devel/p5-Storable

PERL_CONFIGURE=	yes

MAN3=		Getopt::Lucid.3 Getopt::Lucid::Exception.3

.include <bsd.port.mk>
