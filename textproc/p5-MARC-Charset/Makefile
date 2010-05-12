# New ports collection makefile for:	p5-MARC-Charset
# Date created:				1st August, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	MARC-Charset
PORTVERSION=	1.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert MARC-8 encoded strings to UTF-8

RUN_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor

PERL_CONFIGURE=	yes

MAN3=		MARC::Charset.3 \
		MARC::Charset::Constants.3 \
		MARC::Charset::Code.3 \
		MARC::Charset::Compiler.3 \
		MARC::Charset::Table.3

.include <bsd.port.mk>
