# New ports collection makefile for:	gkrellm-reminder
# Date Created:				Sat Dec 15 01:56:45 EST 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	reminder
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# disappeared
PKGNAMEPREFIX=	gkrellm-

MAINTAINER=	pat@FreeBSD.org
COMMENT=	GKrellM plugin that reminds you of important events

RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

# gkrellm2 version with same name
NO_LATEST_LINK=	yes

PLIST_FILES=	libexec/gkrellm/plugins/reminder.so
USE_X_PREFIX=	yes
USE_GNOME=	imlib

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (needs -fPIC)"
.else
BROKEN=		"mastersite disappeared"
.endif
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2005-12-11

do-install:
	@${INSTALL_DATA} ${WRKSRC}/reminder.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.post.mk>
