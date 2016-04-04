# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Nmap-Scanner
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perform and manipulate nmap scans using perl

BUILD_DEPENDS=	nmap:security/nmap \
		p5-Class-Generate>=0:devel/p5-Class-Generate \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
