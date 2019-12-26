# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feather
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script for managing tarsnap backups

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		tarsnap>=0:sysutils/tarsnap

USE_GITHUB=	yes
GH_ACCOUNT=	danrue

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/feather etc/feather.yaml.dist

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README.md
PORTEXAMPLES=	feather.cron.d.example

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/feather ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/feather.yaml.dist ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
