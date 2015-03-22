# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/ \
		https://bitbucket.org/eradman/entr/get/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

# This software has code under BSD2CLAUSE license.
# All the code used in FreeBSD is under ISCL license.
LICENSE=	ISCL

WRKSRC=		${WRKDIR}/eradman-entr-fb68d8f869d5

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
PLIST_FILES=	bin/entr man/man1/entr.1.gz bin/reload-browser

OPTIONS_DEFINE=	RELOAD-BROWSER
RELOAD-BROWSER_DESC=	Script to refresh the active tab in your browser
RELOAD-BROWSER_RUN_DEPENDS=	xdotool:${PORTSDIR}/x11/xdotool

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
