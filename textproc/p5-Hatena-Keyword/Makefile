# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Hatena-Keyword
PORTVERSION=	0.05
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NAOYA
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Extract Hatena Keywords in a string

BUILD_DEPENDS=	p5-Cache>=0:devel/p5-Cache \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		ja-p5-Jcode>=0:japanese/p5-Jcode \
		p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS=	p5-Cache>=0:devel/p5-Cache \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler \
		ja-p5-Jcode>=0:japanese/p5-Jcode \
		p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
