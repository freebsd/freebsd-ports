# New ports collection makefile for:	p5-IMDB-Film
# Date created:		2006-08-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IMDB-Film
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STEPANOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO Perl interface to the movies database IMDB

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Cache/FileCache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		p5-HTML-Parser>=3.34:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=5.800:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		IMDB::BaseClass.3 IMDB::Film.3 IMDB::Persons.3

.include <bsd.port.mk>
