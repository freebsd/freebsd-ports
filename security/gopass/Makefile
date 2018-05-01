# Created by: Sascha Holzleiter <sascha@root-login.org>
# $FreeBSD$

PORTNAME=	gopass
PORTVERSION=	1.6.11
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	sascha@root-login.org
COMMENT=	Gopass is a rewrite of the pass password manager in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gpg2:security/gnupg

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	justwatchcom

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/gopass \
		etc/bash_completion.d/gopass.sh \
		share/zsh/site-functions/_gopass

post-install:
	@${STAGEDIR}${PREFIX}/bin/gopass completion bash > ${WRKDIR}/gopass.comp.sh
	@${STAGEDIR}${PREFIX}/bin/gopass completion zsh > ${WRKDIR}/gopass.comp.zsh
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKDIR}/gopass.comp.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/gopass.sh
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/gopass.comp.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_gopass

.include <bsd.port.mk>
