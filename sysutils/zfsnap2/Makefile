# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfsnap
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0-beta2
CATEGORIES=	sysutils
PKGNAMESUFFIX=	2

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Portable performant script to make rolling ZFS snapshots easy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
USE_GITHUB=	yes
GH_TAGNAME=	af91bd21c848751176ccce0ae314e3c0feb75cc5

OPTIONS_DEFINE=		BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH
OPTIONS_SUB=	yes

PORTDOCS=	AUTHORS NEWS PORTABILITY README.md

post-patch:
	@${REINPLACE_CMD} -e "s,# ZFSNAP_LIB_DIR=.*,ZFSNAP_LIB_DIR=${PREFIX}/share/zfsnap,g" ${WRKSRC}/sbin/zfsnap.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sbin/zfsnap.sh ${STAGEDIR}${PREFIX}/sbin/zfsnap
	cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share
	${INSTALL_MAN} ${WRKSRC}/man/man8/zfsnap.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/zfsnap.8
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} completion ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} periodic ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/${file}
.endfor

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/zfsnap-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/zfsnap.sh

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/zfsnap-completion.bash \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_zfsnap

.include <bsd.port.mk>
