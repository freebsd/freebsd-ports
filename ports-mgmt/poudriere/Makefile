# New ports collection makefile for:	poudriere
# Date created:		2012-01-31
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	poudriere
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://files.etoilebsd.net/poudriere/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Port build and test system

LICENSE=	BSD

NO_BUILD=	yes
MANCOMPRESSED=	yes
MAN8=	poudriere.8

OPTIONS+=	ZSH "Install zsh completion" off

PLIST_FILES=	etc/poudriere.conf.sample \
		bin/poudriere \
		share/poudriere/common.sh \
		share/poudriere/test_ports.sh \
		share/poudriere/ports.sh \
		share/poudriere/pbi.sh \
		share/poudriere/jail.sh \
		share/poudriere/bulk.sh \
		share/poudriere/cron.sh \
		share/poudriere/queue.sh \
		poudriere/cron/.keep

PLIST_DIRS=	share/poudriere \
		poudriere/cron \
		poudriere

.include <bsd.port.options.mk>

.if defined(WITH_ZSH)
PLIST_FILES+=	share/zsh/site-functions/_poudriere
PLIST_DIRSTRY+=	share/zsh/site-functions
PLIST_DIRSTRY+=	share/zsh/
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	@${TOUCH} ${PREFIX}/poudriere/cron/.keep
.if defined(WITH_ZSH)
	@${MKDIR} ${PREFIX}/share/zsh/site-functions/
	@${INSTALL_DATA} ${WRKSRC}/zsh-completions ${PREFIX}/share/zsh/site-functions/_poudriere
.endif

.include <bsd.port.mk>
