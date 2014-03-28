# $FreeBSD$

PORTNAME=	portmaster
PORTVERSION=	3.17.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME}/ \
  		http://mirror.shatow.net/freebsd/${PORTNAME}/ \
		GH
MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_COMMIT=	7ab77f5

OPTIONS_DEFINE=	BASH ZSH

PLIST_FILES=	sbin/portmaster \
		etc/portmaster.rc.sample \
		man/man8/portmaster.8.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
PLIST_FILES+=	etc/bash_completion.d/portmaster.sh
PLIST_DIRSTRY+=	etc/bash_completion.d
.endif

.if ${PORT_OPTIONS:MZSH}
PLIST_FILES+=	share/zsh/site-functions/_portmaster
PLIST_DIRSTRY+=	share/zsh/site-functions share/zsh
.endif

verify: checksum

do-build:
.for file in portmaster files/portmaster.rc.sample
	${SED} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/${file} \
	  > ${WRKDIR}/${file:T}
.endfor
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portmaster \
	    ${STAGEDIR}${PREFIX}/sbin/portmaster
	${INSTALL_DATA} ${WRKDIR}/portmaster.rc.sample \
	    ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/files/portmaster.8 \
	    ${STAGEDIR}${MAN8PREFIX}/man/man8

post-install:
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/files/bash-completions \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/portmaster.sh
.endif
.if ${PORT_OPTIONS:MZSH}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/files/zsh-completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_portmaster
.endif

.include <bsd.port.mk>
