# New ports collection makefile for:	p5-XML-Entities
# Date created:				2010-10-1
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$

PORTNAME=	XML-Entities
PORTVERSION=	1.0000
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		XML::Entities.3pm XML::Entities::Data.3pm download-entities.pl.3pm
MAN1=		download-entities.pl.1

.include <bsd.port.mk>
