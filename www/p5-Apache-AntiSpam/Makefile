# New ports collection makefile for:	p5-Apache-AntiSpam
# Date created:				11 June 2002
# Whom:					Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Apache-AntiSpam
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Email/Find.pm:${PORTSDIR}/mail/p5-Email-Find
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::AntiSpam.3 \
		Apache::AntiSpam::HTMLEncode.3 \
		Apache::AntiSpam::NoSpam.3 \
		Apache::AntiSpam::Heuristic.3 \

.include <bsd.port.mk>
