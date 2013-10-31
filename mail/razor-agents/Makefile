# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	razor-agents
PORTVERSION=	2.84
CATEGORIES=	mail
MASTER_SITES=	SF/razor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A distributed, collaborative, spam detection and filtering network

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure patch
MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	lib/Razor2/Client/*.pm \
		lib/Razor2/Signature/*.pm \
		lib/Razor2/*.pm

MAKE_ARGS+=	PERLPREFIX=${PREFIX}
USE_BZIP2=	yes

PORTSCOUT=	skipv:2.85

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's|/etc/razor|${PREFIX}/etc|g'
	@${PERL} -pi -e 's,share/man,man,g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
