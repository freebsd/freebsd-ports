PORTNAME=	razor-agents
PORTVERSION=	2.85
CATEGORIES=	mail
MASTER_SITES=	SF/razor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Distributed, collaborative, spam detection and filtering network
WWW=		https://sourceforge.net/projects/razor/

LICENSE=	ART20

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	configure patch

SHEBANG_FILES=	lib/Razor2/Client/*.pm \
		lib/Razor2/Signature/*.pm \
		lib/Razor2/*.pm

MAKE_ARGS+=	PERLPREFIX=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's|/etc/razor|${PREFIX}/etc|g'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Razor2/Preproc/deHTMLxs/deHTMLxs.so

.include <bsd.port.mk>
