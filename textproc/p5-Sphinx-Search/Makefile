# New ports collection makefile for:	p5-Sphinx-Search
# Date created:				Thu Aug 20 15:21:22 EDT 2009
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	Sphinx-Search
PORTVERSION=	0.26.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJSCHUTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sphinx search engine API Perl client

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-File-SearchPath>=0:${PORTSDIR}/devel/p5-File-SearchPath \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-File-SearchPath>=0:${PORTSDIR}/devel/p5-File-SearchPath \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class

PERL_CONFIGURE=	yes

MAN3=		Sphinx::Search.3

.include <bsd.port.mk>
