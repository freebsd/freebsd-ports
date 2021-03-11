# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googler
PORTVERSION=	4.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google Search, Google Site Search, Google News from the terminal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.5+ shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	jarun

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/googler man/man1/googler.1.gz

SHEBANG_FILES=	googler

post-patch:
	@${SED} -i.bak 's/^\(ENABLE_SELF_UPGRADE_MECHANISM = \)True$$/\1False/' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}/${MANPREFIX}/man/man1/

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest tests

.include <bsd.port.mk>
