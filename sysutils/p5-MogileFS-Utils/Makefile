PORTNAME=	MogileFS-Utils
PORTVERSION=	2.30
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MogileFS tools
WWW=		https://metacpan.org/release/MogileFS-Utils

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-MogileFS-Client>=1.16:sysutils/p5-MogileFS-Client \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|MogileFS-Utils|MogileFS::Utils|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
