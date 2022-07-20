PORTNAME=	Net-SinFP
PORTVERSION=	2.10
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Full operating system stack fingerprinting suite

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.Artistic

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Gomor>=1.00:devel/p5-Class-Gomor \
		p5-DBIx-SQLite-Simple>=0.33:databases/p5-DBIx-SQLite-Simple \
		p5-Net-Packet-Target>=1.00:net/p5-Net-Packet-Target \
		p5-Net-Packet>=3.20:net/p5-Net-Packet

USES=		perl5
USE_PERL5=	configure

INSTALL_TARGET=	pure_install

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/.*EXE_FILES.*//' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
