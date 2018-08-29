# $FreeBSD$

PORTNAME=	Parse-Netstat
PORTVERSION=	0.14
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Parse the output of netstat command

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install
TEST_DEPENDS=	p5-File-Slurper>=0.011:devel/p5-File-Slurper

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

post-patch:
	@${RM} -r ${WRKSRC}/share
	@${REINPLACE_CMD} -e '/.*netstat-samples.*/d' \
		${WRKSRC}/MANIFEST
	@${REINPLACE_CMD} -e '/install_share.*/d' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
