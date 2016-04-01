# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	AMF-Perl
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIMONF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flash Remoting in Perl

RUN_DEPENDS=	p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-DBI>=0:databases/p5-DBI

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	@${PERL} -pi -e 's/=(?==head)//g' ${WRKSRC}/lib/AMF/Perl.pm

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
