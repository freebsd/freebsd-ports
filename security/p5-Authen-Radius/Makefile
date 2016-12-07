# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-Radius
PORTVERSION=	0.25
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to provide simple Radius client facilities

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Data-HexDump>=0.02:devel/p5-Data-HexDump \
		p5-Net-IP>=1.26:net-mgmt/p5-Net-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

REINPLACE_ARGS=	-i ''
USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

RADDBFILES=	dictionary \
		dictionary.ascend \
		dictionary.cisco \
		dictionary.compat \
		dictionary.livingston \
		dictionary.quintum \
		dictionary.rfc2869 \
		dictionary.shiva \
		dictionary.tunnel \
		dictionary.usr \
		dictionary.versanet \
		dictionary.xtradius

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/raddb|${DATADIR}|' ${WRKSRC}/Radius.pm
	@${RM} ${WRKSRC}/install-radius-db.PL

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/raddb/ && ${INSTALL_DATA} ${RADDBFILES} ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
