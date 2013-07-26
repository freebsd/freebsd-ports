# $FreeBSD$

PORTNAME=	Perl-MinimumVersion
PORTVERSION=	1.32
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Find a minimum required version of perl for Perl code

BUILD_DEPENDS=	p5-File-Find-Rule>=0.32:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Find-Rule-Perl>=1.04:${PORTSDIR}/devel/p5-File-Find-Rule-Perl \
		p5-PPI>=1.215:${PORTSDIR}/textproc/p5-PPI \
		p5-PPIx-Regexp>=0.028:${PORTSDIR}/textproc/p5-PPIx-Regexp \
		p5-Perl-Critic>=1.10.4:${PORTSDIR}/textproc/p5-Perl-Critic \
		p5-Params-Util>=0.25:${PORTSDIR}/devel/p5-Params-Util \
		p5-version>=0.76:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Script>=0:${PORTSDIR}/devel/p5-Test-Script

PERL_CONFIGURE=	yes

MAN1=	perlver.1
MAN3=	Perl::MinimumVersion.3

post-patch:
	@${REINPLACE_CMD} -i '' -e '/Test::/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
