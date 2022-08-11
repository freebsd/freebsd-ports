PORTNAME=	postfwd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	postfix-

MAINTAINER=	andreas.jobs+freebsdbugs@ruhr-uni-bochum.de
COMMENT=	Postfix firewall policy daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Server>=0:net/p5-Net-Server

USES=		perl5 shebangfix
USE_GITHUB=	yes
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	sbin/* tools/*.pl tools/hapolicy/*

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.cf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/man8/* ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/${PORTNAME}3 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tools/request.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/postfwd.plugins.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
