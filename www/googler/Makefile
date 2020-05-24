# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googler
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google Search, Google Site Search, Google News from the terminal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	xclip:x11/xclip
TEST_DEPENDS=	bash:shells/bash \
		gshuf:sysutils/coreutils

USES=		python:3.5+ shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	jarun

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/googler man/man1/googler.1.gz

SHEBANG_FILES=	googler

USE_LOCALE?=	en_US.UTF-8

post-patch:
	@${SED} -i.bak 's/^\(ENABLE_SELF_UPGRADE_MECHANISM = \)True$$/\1False/' \
		${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's/shuf/gshuf/' ${WRKSRC}/tests/test
	@${REINPLACE_CMD} -e 's/python3/${PYTHON_VERSION}/' ${WRKSRC}/tests/test

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}/${MANPREFIX}/man/man1/

do-test:
	@${SETENV} LANG=${USE_LOCALE} LC_ALL=${USE_LOCALE} ${WRKSRC}/tests/test --ci

.include <bsd.port.mk>
