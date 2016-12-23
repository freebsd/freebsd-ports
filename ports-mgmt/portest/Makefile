# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	portest
PORTVERSION=	0.1.8
CATEGORIES=	ports-mgmt

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Patch file automation for FreeBSD-ports

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	ultima1252

NO_BUILD=	yes

PLIST_FILES=	sbin/portest

OPTIONS_DEFINE=		GIT PORTLINT PORTTOOLS POUDRIERE

GIT_DESC=		Git support
GIT_RUN_DEPENDS=	git:devel/git

PORTLINT_DESC=		Portlint support
PORTLINT_RUN_DEPENDS=	portlint:ports-mgmt/portlint

PORTTOOLS_DESC=		Porttools support
PORTTOOLS_RUN_DEPENDS=	port:ports-mgmt/porttools

POUDRIERE_DESC=		Poudriere and parallel build support
POUDRIERE_RUN_DEPENDS=	poudriere:ports-mgmt/poudriere \
			tmux:sysutils/tmux

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portest ${STAGEDIR}${PREFIX}/sbin/portest

.include <bsd.port.mk>
