# New ports collection makefile for:	textproc/p5-Perl-MinimumVersion
# Date created:				25 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-MinimumVersion
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Find a minimum required version of perl for Perl code

RUN_DEPENDS=	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-PPI>=1.118:${PORTSDIR}/textproc/p5-PPI \
		p5-Params-Util>=0.06:${PORTSDIR}/devel/p5-Params-Util \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-version>=0.72.03:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN1=	perlver.1
MAN3=	Perl::MinimumVersion.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
