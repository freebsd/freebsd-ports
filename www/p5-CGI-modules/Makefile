# New ports collection makefile for:	p5-CGI
# Version required:			2.75
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:57:59 jfitz Exp $
#

DISTNAME=	CGI-modules-2.75
PKGNAME=	p5-CGI-2.75
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/URI/Escape.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		CGI::Base.3 CGI::BasePlus.3 CGI::Carp.3 CGI::Form.3 \
		CGI::MiniSvr.3 CGI::Request.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
