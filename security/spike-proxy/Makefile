# Created by: Yonatan <Yonatan@xpert.com>
# $FreeBSD$

PORTNAME=	spike-proxy
PORTVERSION=	1.4.8
CATEGORIES=	security
MASTER_SITES=	http://www.immunitysec.com/downloads/
DISTNAME=	SP${PORTVERSION:tl:C/\.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool looking for vulnerabilities in web applications

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0:${PORTSDIR}/security/py-openssl

USES=		python shebangfix tar:tgz
SHEBANG_FILES=	*.py
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/spkproxy

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${RM} -rf ${WRKSRC}/*.bak
	${CP} -Rp ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${SED} "s|DATADIR|${DATADIR}|" ${SCRIPTDIR}/spkproxy.sh > \
		${STAGEDIR}${PREFIX}/bin/spkproxy.sh
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/spkproxy.sh
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} WHYGPL.txt TODO.txt SpikeUsage.txt \
		README.txt CHANGELOG.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
