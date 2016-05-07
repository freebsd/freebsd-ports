# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	razor-agents
PORTVERSION=	2.84
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/razor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Distributed, collaborative, spam detection and filtering network

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	configure patch
MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	lib/Razor2/Client/*.pm \
		lib/Razor2/Signature/*.pm \
		lib/Razor2/*.pm

MAKE_ARGS+=	PERLPREFIX=${PREFIX}

PORTSCOUT=	skipv:2.85

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's|/etc/razor|${PREFIX}/etc|g'
	@${REINPLACE_CMD} -e '/MAN5/s,man/man5,${SITE_MAN3_REL:S/3/5/},g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
