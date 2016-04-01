# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Crypt-xDBM_File
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module encrypt almost any kind of dbm file

BUILD_DEPENDS=	p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
