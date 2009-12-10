# New ports collection makefile for:	textproc/p5-Perl-MinimumVersion
# Date created:				25 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-MinimumVersion
PORTVERSION=	1.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Find a minimum required version of perl for Perl code

RUN_DEPENDS=	p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Find-Rule-Perl>=1.04:${PORTSDIR}/devel/p5-File-Find-Rule-Perl \
		p5-PPI>=1.205:${PORTSDIR}/textproc/p5-PPI \
		p5-Perl-Critic>=1.10.4:${PORTSDIR}/textproc/p5-Perl-Critic \
		p5-Params-Util>=0.25:${PORTSDIR}/devel/p5-Params-Util \
		p5-Scalar-List-Utils>=1.19:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-version>=0.76:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN1=	perlver.1
MAN3=	Perl::MinimumVersion.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
