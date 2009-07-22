# New ports collection makefile for:	p5-WWW-Spinn3r
# Date created:		2008-03-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Spinn3r
PORTVERSION=	3.00700001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An interface to the Spinn3r API

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		WWW::Spinn3r.3 \
		WWW::Spinn3r::Synced.3

.include <bsd.port.mk>
