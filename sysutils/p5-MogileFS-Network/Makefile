PORTNAME=	MogileFS-Network
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HACHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network awareness and extensions for p5-MogileFS-Server
WWW=		https://metacpan.org/release/MogileFS-Network

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-Net-Patricia>=0:net/p5-Net-Patricia \
		p5-MogileFS-Server>=2.50:sysutils/p5-MogileFS-Server

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|MogileFS-Network|MogileFS::Network|' \
	    ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
