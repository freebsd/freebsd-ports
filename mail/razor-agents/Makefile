# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	razor-agents
PORTVERSION=	2.84
CATEGORIES=	mail
MASTER_SITES=	SF/razor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A distributed, collaborative, spam detection and filtering network

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch
MAKE_JOBS_UNSAFE=	yes

MAKE_ARGS+=	PERLPREFIX=${PREFIX}
USE_BZIP2=	yes

MAN1=		razor-revoke.1 razor-admin.1 razor-report.1 razor-check.1
MAN3=		Razor2::Errorhandler.3 Razor2::Preproc::deHTMLxs.3 \
		Razor2::Syslog.3
MAN5=		razor-agents.5 razor-whitelist.5 razor-agent.conf.5

PORTSCOUT=	skipv:2.85

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e 's|/etc/razor|${PREFIX}/etc|g'
	@${PERL} -pi -e 's,share/man,man,g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
