# New ports collection makefile for:	www/p5-CGI.pm
# Date created:				12 July 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI.pm
PORTVERSION=	2.89
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CGI.3 CGI::Apache.3 CGI::Carp.3 CGI::Cookie.3 CGI::Fast.3 \
	CGI::Pretty.3 CGI::Push.3 CGI::Switch.3 CGI::Util.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e '$$_ = "" if /INSTALLDIRS|5\.6\.0/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
