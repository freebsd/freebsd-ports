# New ports collection makefile for:	p5-Mail-ClamAV
# Date created:		2003-11-24
# Whom:			Jan-Peter Koopmann <Jan-Peter.Koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	Mail-ClamAV
PORTVERSION=	0.28
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the clamav virus scanner

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		clamscan:${PORTSDIR}/security/clamav
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

PERL_CONFIGURE=	yes

MAN3=		Mail::ClamAV.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
