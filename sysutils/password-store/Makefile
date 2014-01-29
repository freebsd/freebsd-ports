# $FreeBSD$

PORTNAME=	password-store
PORTVERSION=	1.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://git.zx2c4.com/password-store/snapshot/

MAINTAINER=	milki@FreeBSD.org
COMMENT=	Stores, retrieves, generates, and synchronizes passwords securely

LICENSE=	GPLv2

RUN_DEPENDS=	bash>=0:${PORTSDIR}/shells/bash \
		gnupg>=2:${PORTSDIR}/security/gnupg \
		pwgen>=0:${PORTSDIR}/sysutils/pwgen \
		tree>=0:${PORTSDIR}/sysutils/tree

OPTIONS_DEFINE=		GIT XCLIP

GIT_DESC=		Enable git storage
XCLIP_DESC=		Enable xclip feature

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	git>=0:${PORTSDIR}/devel/git
.endif

.if ${PORT_OPTIONS:MXCLIP}
RUN_DEPENDS+=	base64>=0:${PORTSDIR}/converters/base64 \
		xclip>=0:${PORTSDIR}/x11/xclip
.endif

do-patch:
.if empty(PORT_OPTIONS:MGIT) && empty(PORT_OPTIONS:MXCLIP)
	(cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/linuxism+git+xclip.patch)
.elif empty(PORT_OPTIONS:MGIT)
	(cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/linuxism+git.patch)
.elif empty(PORT_OPTIONS:MXCLIP)
	(cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/linuxism+xclip.patch)
.else
	(cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/linuxism.patch)
.endif

# empty to skip make
do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/password-store.sh ${PREFIX}/libexec/pass
	@${LN} -s ${PREFIX}/libexec/pass ${PREFIX}/bin/pass

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/pass.bash-completion ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/pass.zsh-completion ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/pass.fish-completion ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/man/pass.1 ${MANPREFIX}/man/man1/pass.1

MAN1=	pass.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/pass \
		libexec/pass \
		share/password-store/pass.bash-completion \
		share/password-store/pass.zsh-completion \
		share/password-store/pass.fish-completion
PLIST_DIRS=	share/password-store

.include <bsd.port.mk>
