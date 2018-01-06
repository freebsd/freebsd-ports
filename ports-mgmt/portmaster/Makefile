# $FreeBSD$

PORTNAME=	portmaster
PORTVERSION=	3.18
PORTREVISION=	8
CATEGORIES=	ports-mgmt

MAINTAINER=	se@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

OPTIONS_DEFINE=	BASH ZSH
OPTIONS_DEFAULT=BASH ZSH

PLIST_FILES=	sbin/portmaster \
		etc/portmaster.rc.sample \
		man/man8/portmaster.8.gz

BASH_PLIST_FILES=	etc/bash_completion.d/portmaster.sh
ZSH_PLIST_FILES=	share/zsh/site-functions/_portmaster

NO_ARCH=	yes

verify: checksum

do-build:
.for file in portmaster files/portmaster.rc.sample files/portmaster.8
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
	    -e 's#%%PKGNAME%%#${PKGNAME}#g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portmaster \
	    ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/files/portmaster.rc.sample \
	    ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/files/portmaster.8 \
	    ${STAGEDIR}${MAN8PREFIX}/man/man8

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/files/bash-completions \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/portmaster.sh

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/files/zsh-completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_portmaster

.include <bsd.port.mk>
