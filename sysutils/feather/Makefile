# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feather
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script for managing tarsnap backups

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml \
		tarsnap>=0:sysutils/tarsnap

USES=		python:2,run
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	danrue

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README.md
PORTEXAMPLES=	feather.cron.d.example
PLIST_FILES=	bin/feather etc/feather.yaml.dist

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
