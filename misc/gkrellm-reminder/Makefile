# New ports collection makefile for:	gkrellm-reminder
# Date Created:				Sat Dec 15 01:56:45 EST 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	reminder
PORTVERSION=	0.3.5
CATEGORIES=	misc
MASTER_SITES=	http://www.engr.orst.edu/~simonsen/reminder/
PKGNAMEPREFIX=	gkrellm-

MAINTAINER=	pat@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib

do-install:
	@${INSTALL_DATA} ${WRKSRC}/reminder.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
