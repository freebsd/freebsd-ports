# New ports collection makefile for:	p5-chklinks
# Date created:				2007/06/07
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	chklinks
PORTVERSION=	3.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Locale/IMACAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A non-threaded Perl link checker

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN1=		chklinks.1

PLIST_FILES=	bin/chklinks \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/chklinks/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/chklinks

.include <bsd.port.mk>
