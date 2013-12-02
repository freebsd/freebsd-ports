# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	please
PORTVERSION=	1.2
CATEGORIES=	security

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Execute a command as root

LICENSE=	BSD

BUILD_DEPENDS=	rst2man:${PORTSDIR}/textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	MagikBSD
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	078daa7

NEED_ROOT=	yes
PLIST_FILES=	bin/please man/man1/please.1.gz

.include <bsd.port.mk>
