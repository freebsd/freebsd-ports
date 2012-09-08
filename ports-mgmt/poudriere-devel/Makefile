# $FreeBSD$

PORTNAME=	poudriere
PORTVERSION=	2.0.99.20120908
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://fossil.etoilebsd.net/poudriere/tarball/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

FSL_CHKIN=	7befeb3094
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${FSL_CHKIN}
PKGNAMESUFFIX=	-devel

NO_BUILD=	yes
MANCOMPRESSED=	yes
MAN8=	poudriere.8

CONFLICTS_INSTALL=	poudriere-[0-9]*

OPTIONS_DEFINE=	ZSH
ZSH_DESC=	Install zsh completion

PLIST_FILES=	etc/poudriere.conf.sample \
		bin/poudriere \
		share/poudriere/clean.sh \
		share/poudriere/common.sh \
		share/poudriere/test_ports.sh \
		share/poudriere/ports.sh \
		share/poudriere/pbi.sh \
		share/poudriere/jail.sh \
		share/poudriere/bulk.sh \
		share/poudriere/cron.sh \
		share/poudriere/queue.sh \
		share/poudriere/options.sh \

PLIST_DIRS=	share/poudriere \

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZSH}
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.endif

post-install:
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions ${PREFIX}/share/zsh/site-functions/_poudriere
.endif

.include <bsd.port.mk>
