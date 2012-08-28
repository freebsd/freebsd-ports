# New ports collection makefile for:	poudriere
# Date created:		2012-01-31
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poudriere
PORTVERSION=	2.0.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://files.etoilebsd.net/poudriere/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

NO_BUILD=	yes
MANCOMPRESSED=	yes
MAN8=	poudriere.8

OPTIONS_DEFINE=	ZSH
ZSH_DESC=	Install zsh completion

CONFLICTS_INSTALL=	poudriere-devel-*

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

PLIST_DIRS=	share/poudriere

.include <bsd.port.options.mk>

.if defined(WITH_ZSH)
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
.if defined(WITH_ZSH)
	@${MKDIR} ${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions ${PREFIX}/share/zsh/site-functions/_poudriere
.endif

.include <bsd.port.mk>
