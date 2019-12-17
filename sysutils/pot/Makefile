# Created by: Luca Pizzamiglio <pizzamig@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pot
PORTVERSION=	0.10.2
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Container framework for FreeBSD

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	potnet:sysutils/potnet \
	ncat:security/nmap \
	${LOCALBASE}/share/freebsd/MANIFESTS/amd64-amd64-11.2-RELEASE:misc/freebsd-release-manifests

USE_RC_SUBR=	pot

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS ZSH

ZSH_DESC=	Zsh Autocompletion support

OPTIONS_DEFAULT=	ZSH
OPTIONS_SUB=	yes

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
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/dns.sh \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/dns \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/fbsd-update.sh \
		${STAGEDIR}${ETCDIR}/flavours
	${INSTALL_DATA} ${WRKSRC}/etc/pot/flavours/slim.sh \
		${STAGEDIR}${ETCDIR}/flavours

do-install-ZSH-on:
	( cd ${WRKSRC}/share/zsh && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/zsh)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/Installation.md \
		${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/share/doc/pot/QuickStart.md \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
