# $FreeBSD$

PORTNAME=	password-store
PORTVERSION=	1.6.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://git.zx2c4.com/password-store/snapshot/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Stores, retrieves, generates, and synchronizes passwords securely

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		getopt>=0:misc/getopt \
		gnupg>=2:security/gnupg \
		pwgen>=0:sysutils/pwgen \
		tree>=1.7:sysutils/tree

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		CONTRIB EXAMPLES GIT XCLIP
OPTIONS_DEFAULT=	CONTRIB XCLIP
OPTIONS_SUB=		yes

GIT_DESC=		Enable git storage
XCLIP_DESC=		Enable xclip feature
CONTRIB_DESC=		Include shell completions, import scripts, related projects

GIT_RUN_DEPENDS=	git>=0:devel/git
XCLIP_RUN_DEPENDS=	base64>=0:converters/base64 \
			xclip>=0:x11/xclip

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -Ee 's|GETOPT="getopt"|GETOPT="${LOCALBASE}/bin/getopt"|' ${WRKSRC}/src/password-store.sh
	@${REINPLACE_CMD} -Ee 's|SHRED="shred -f -z"|SHRED="rm -P -f"|' ${WRKSRC}/src/password-store.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/password-store.sh ${STAGEDIR}${PREFIX}/libexec/pass
	${LN} -s ${PREFIX}/libexec/pass ${STAGEDIR}${PREFIX}/bin/pass
	${INSTALL_MAN} ${WRKSRC}/man/pass.1 ${STAGEDIR}${MANPREFIX}/man/man1/pass.1

do-install-CONTRIB-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/src/completion && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/pass.zsh-completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_pass
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/pass.bash-completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/password-store
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/pass.fish-completion ${STAGEDIR}${PREFIX}/share/fish/completions/password-store.fish

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/man/example-filter.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
