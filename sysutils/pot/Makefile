PORTNAME=	pot
DISTVERSION=	0.15.5
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Container framework for FreeBSD
WWW=		https://github.com/pizzamig/pot/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	potnet:sysutils/potnet \
		ncat:security/nmap \
		freebsd-release-manifests>0:misc/freebsd-release-manifests \
		signify:security/signify
TEST_DEPENDS=	flock:sysutils/flock

GROUPS=		pot

USE_RC_SUBR=	pot pot_early

SUB_FILES=	pkg-message pot.8

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS ZSH

ZSH_DESC=	Zsh Autocompletion support

OPTIONS_DEFAULT=	ZSH
OPTIONS_SUB=	yes

TEST_WRKSRC=	${WRKSRC}/tests

PORTDOCS=	*

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

do-test:
	( cd ${TEST_WRKSRC} && ./test-suite.sh )

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/Installation.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/QuickStart.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/Images.md \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
