# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Lingua-EN-NamedEntity
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Basic Named Entity Extraction algorithm

RUN_DEPENDS=	p5-Lingua-Stem>=0:${PORTSDIR}/textproc/p5-Lingua-Stem \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::NamedEntity.3

.include <bsd.port.mk>
