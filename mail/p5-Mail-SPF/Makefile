# Created by: gmc@sonologic.nl
# $FreeBSD$

PORTNAME=	Mail-SPF
PORTVERSION=	2.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented implementation of Sender Policy Framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Error>=0:lang/p5-Error \
		p5-Net-DNS>=0.62:dns/p5-Net-DNS \
		p5-Net-DNS-Resolver-Programmable>=0.003:dns/p5-Net-DNS-Resolver-Programmable \
		p5-NetAddr-IP>=4:net-mgmt/p5-NetAddr-IP \
		p5-URI>=1.13:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

CONFLICTS_INSTALL=	p5-Mail-SPF-Query-[0-9]*

CONFIGURE_ARGS=	--install_path sbin=${PREFIX}/sbin
NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5 shebangfix

SHEBANG_FILES=	bin/spfquery sbin/spfd

post-patch:
	@${MV} ${WRKSRC}/sbin/spfd ${WRKSRC}/sbin/spfd.pl
	@${MV} ${WRKSRC}/bin/spfquery ${WRKSRC}/bin/spfquery.pl
	@${REINPLACE_CMD} -e 's|spfd|&.pl|; s|spfquery|&.pl|' ${WRKSRC}/Build.PL ${WRKSRC}/MANIFEST ${WRKSRC}/README

.include <bsd.port.mk>
