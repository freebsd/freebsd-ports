# New ports collection makefile for:   p5-CGI-Upload
# Date created:                        21 June 2003
# Whom:                                Daniel B. Hemmerich
#
# $FreeBSD$
#

PORTNAME=      CGI-Upload
PORTVERSION=   1.05
CATEGORIES=    www perl5
MASTER_SITES=  ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=    CGI
PKGNAMEPREFIX= p5-

MAINTAINER=    ports-freebsd@FreeBSDsecurity.com
COMMENT=       CGI class for handling browser file uploads

BUILD_DEPENDS= ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/BrowserDetect.pm:${PORTSDIR}/www/p5-HTTP-BrowserDetect \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic

PERL_CONFIGURE=        yes

MAN3=          CGI::Upload.3
MANPREFIX=     ${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
