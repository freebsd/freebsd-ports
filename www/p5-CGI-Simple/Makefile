# New ports collection makefile for:	p5-CGI-Simple
# Date created:		16 November 2004
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Simple
PORTVERSION=	0.077
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/J/JF/JFREEMAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:C/CGI/Cgi/}-${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A simple totally OO CGI interface that is CGI.pm compliant

PERL_CONFIGURE=	yes

MAN3=		CGI::Simple.3 \
		CGI::Simple::Cookie.3 \
		CGI::Simple::Standard.3 \
		CGI::Simple::Util.3

.include <bsd.port.mk>
