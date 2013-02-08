# $FreeBSD$

PORTNAME=	portmaster
PORTVERSION=	3.14
PORTREVISION=	9
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH \
  		http://mirror.shatow.net/freebsd/portmaster/
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	portmaster
GH_COMMIT=	31009f6
GH_TAGNAME=	${GH_COMMIT}

OPTIONS_DEFINE=	BASH ZSH PKGNGPATCH
.if defined(WITH_PKGNG)
OPTIONS_DEFAULT+=	PKGNGPATCH
.endif
BASH_DESC=	Install programmable completions for Bash
ZSH_DESC=	Install programmable completions for zsh
PKGNGPATCH_DESC=Enable PKGNG support

PLIST_FILES=	sbin/portmaster etc/portmaster.rc.sample

MAN8=		portmaster.8

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPKGNGPATCH}
PATCH_SITES+=	http://mirror.shatow.net/freebsd/portmaster/
PATCHFILES+=	patch-portmaster-pkgng.gz
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-files::with_pkgng_current
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-files::pkg_install-pkgng-ss
.  if ${PORT_OPTIONS:MZSH}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-files::zsh-completions
.  endif
.endif

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
	${INSTALL_SCRIPT} ${WRKDIR}/portmaster ${PREFIX}/sbin/portmaster
	${INSTALL_DATA} ${WRKDIR}/portmaster.rc.sample ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/files/portmaster.8 ${MAN8PREFIX}/man/man8

post-install:
.if ${PORT_OPTIONS:MBASH}
	${MKDIR} ${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/files/bash-completions \
		${PREFIX}/etc/bash_completion.d/portmaster.sh
.endif
.if ${PORT_OPTIONS:MZSH}
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/files/zsh-completions \
		${PREFIX}/share/zsh/site-functions/_portmaster
.endif
.if ${PORT_OPTIONS:MPKGNGPATCH}
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
