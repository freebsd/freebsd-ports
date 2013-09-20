# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=	XML-Entities
PORTVERSION=	1.0001
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		XML::Entities.3pm XML::Entities::Data.3pm download-entities.pl.3pm
MAN1=		download-entities.pl.1

NO_STAGE=	yes
.include <bsd.port.mk>
