# Created by: Yonatan <Yonatan@xpert.com>
# $FreeBSD$

PORTNAME=	spike-proxy
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.immunitysec.com/downloads/
DISTNAME=	SP${PORTVERSION:tl:C/\.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool looking for vulnerabilities in web applications

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR}

USES=		python:2.7 shebangfix tar:tgz
SHEBANG_FILES=	*.py
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/spkproxy

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${RM} -r ${WRKSRC}/*.bak
	${CP} -Rp ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${SED} "s|DATADIR|${DATADIR}|" ${SCRIPTDIR}/spkproxy.sh > \
		${STAGEDIR}${PREFIX}/bin/spkproxy.sh
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/spkproxy.sh

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} WHYGPL.txt TODO.txt SpikeUsage.txt \
		README.txt CHANGELOG.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
