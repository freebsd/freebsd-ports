PORTNAME=	pot
DISTVERSION=	0.16.0
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Container framework for FreeBSD
WWW=		https://github.com/bsdpot/pot/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	freebsd-release-manifests>0:misc/freebsd-release-manifests \
		ncat:security/nmap \
		potnet>=0.5.0:sysutils/potnet \
		signify:security/signify
TEST_DEPENDS=	flock:sysutils/flock

USE_GITHUB=	yes
GH_ACCOUNT=	bsdpot
USE_RC_SUBR=	pot pot_early

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message pot.8

TEST_WRKSRC=	${WRKSRC}/tests

GROUPS=		pot

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS ZSH
OPTIONS_DEFAULT=	ZSH
OPTIONS_SUB=		yes

ZSH_DESC=	Zsh Autocompletion support

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pot \
	    ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	( cd ${WRKSRC}/share/pot && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/pot.default.conf \
		${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pot/pot.conf.sample \
		${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/etc/pot/flavours/dns.sh \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/dns \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_SCRIPT} ${WRKSRC}/etc/pot/flavours/fbsd-update.sh \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_SCRIPT} ${WRKSRC}/etc/pot/flavours/slim.sh \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_MAN} ${WRKDIR}/pot.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-install-ZSH-on:
	( cd ${WRKSRC}/share/zsh && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/zsh)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/Installation.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/QuickStart.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/Images.md \
		${STAGEDIR}${DOCSDIR}/

do-test:
	( cd ${TEST_WRKSRC} && ./test-suite.sh )

.include <bsd.port.mk>
