# $FreeBSD$

PORTNAME=	tremc
DISTVERSION=	g20171202
CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lbdm@privacychain.ch
COMMENT=	Console client for the BitTorrent client Transmission

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.4+ shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	louipc
GH_TAGNAME=	e06d08d

NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/bash-completion/completions/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GEOIP XEROX

XEROX_DESC=	Copy magnet links to the system clipboard

GEOIP_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/GeoIP.so:net/py-GeoIP@${PY_FLAVOR}
XEROX_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xerox/__init__.py:devel/py-xerox@${PY_FLAVOR}

do-install:

	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL} -d ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/completion/bash/transmission-remote-cli-bash-completion.sh \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}

.include <bsd.port.mk>
