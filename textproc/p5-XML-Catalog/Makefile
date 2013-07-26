# Created by: ijliao
# $FreeBSD$

PORTNAME=	XML-Catalog
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resolve public identifiers and remap system identifiers

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_DOS2UNIX=	Catalog.pm

MAN3=		XML::Catalog.3

.include <bsd.port.mk>
