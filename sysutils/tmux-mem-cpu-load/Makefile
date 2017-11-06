# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmux-mem-cpu-load
PORTVERSION=	3.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	CPU, RAM, and load monitor for use with tmux

LICENSE=	APACHE20

RUN_DEPENDS=	tmux:sysutils/tmux

BROKEN_powerpc64=	fails to compile: Compiler GNU 4.2.1 has no C++11 support

USE_GITHUB=	yes
GH_ACCOUNT=	thewtex

USES=		cmake

PLIST_FILES=	bin/tmux-mem-cpu-load

.include <bsd.port.mk>
