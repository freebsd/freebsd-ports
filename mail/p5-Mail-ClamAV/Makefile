# New ports collection makefile for:	p5-Mail-ClamAV
# Date created:		2003-11-24
# Whom:			Jan-Peter Koopmann <Jan-Peter.Koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	Mail-ClamAV
PORTVERSION=	0.12
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	j.koopmann@seceidos.de
COMMENT=	Perl extension for the clamav virus scanner

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		clamscan:${PORTSDIR}/security/clamav
RUN_DEPENDS=	${BUILD_DEPENDS}

INSTALLS_SHLIB=	yes

PERL_CONFIGURE=	yes

MAN3=		Mail::ClamAV.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"requires perl 5.6.x or later. Install lang/perl5 and try again"
.endif

.include <bsd.port.post.mk>
