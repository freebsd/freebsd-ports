# New ports collection makefile for:	www/p5-CGI.pm
# Date created:				12 July 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI.pm
PORTVERSION=	2.99
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Simple Common Gateway Interface Class for Perl

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN3=		CGI.3 CGI::Apache.3 CGI::Carp.3 CGI::Cookie.3 \
		CGI::Fast.3 CGI::Pretty.3 CGI::Push.3 CGI::Switch.3 \
		CGI::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
