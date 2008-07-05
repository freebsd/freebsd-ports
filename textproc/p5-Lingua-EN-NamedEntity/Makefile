# New ports collection makefile for:	p5-Lingua-EN-NamedEntity
# Date created:				2006-07-21
# Whom:					Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-NamedEntity
PORTVERSION=	1.9
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic Named Entity Extraction algorithm

BUILD_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Lingua/Stem/En.pm:${PORTSDIR}/textproc/p5-Lingua-Stem \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::NamedEntity.3

.include <bsd.port.mk>
