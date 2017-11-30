# Created by: Nobutaka Mantani <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dshell
PORTVERSION=	3.0.20150220
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Extensible network forensic analysis framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pygeoip>0:net/py-pygeoip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dpkt>0:net/py-dpkt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipy>0:net-mgmt/py-ipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypcap>0:net/py-pypcap@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
USES=		python:-2.7 shebangfix
NO_ARCH=	yes
SHEBANG_FILES=	bin/*.py

GH_ACCOUNT=	USArmyResearchLab
GH_PROJECT=	Dshell
GH_TAGNAME=	46e691c

OPTIONS_DEFINE=	DOCS

MAKE_ENV+=	PYTHON_CMD=${PYTHON_CMD}

post-patch:
.for f in bin/generate-dshellrc.py doc/generate-doc.sh
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/${f}
	${REINPLACE_CMD} -e 's|pydoc|${LOCALBASE}/bin/pydoc${PYTHON_VER}|' ${WRKSRC}/${f}
.endfor

post-build:
	${RM} -r ${WRKSRC}/lib/${PYTHON_VERSION}
	${REINPLACE_CMD} -e 's|${WRKSRC}|${ETCDIR}|' ${WRKSRC}/dshell ${WRKSRC}/dshell-decode
	${REINPLACE_CMD} -e 's|BINPATH=${WRKSRC}/bin|BINPATH=${PREFIX}/libexec/dshell|' \
		-e 's|DSHELL=${WRKSRC}|DSHELL=${PYTHON_SITELIBDIR}|' \
		-e 's|DATAPATH=${WRKSRC}/share|DATAPATH=${DATADIR}|' \
		-e 's|DECODERPATH=${WRKSRC}/decoders|DECODERPATH=${PYTHON_SITELIBDIR}/dshell/decoders|' \
		-e 's|LIBPATH=${WRKSRC}/lib|LIBPATH=${PYTHON_SITELIBDIR}/dshell|' \
		${WRKSRC}/.dshellrc
	(cd ${WRKSRC}/doc; ${REINPLACE_CMD} -e 's|${WRKSRC}|${PYTHON_SITELIBDIR}/dshell|g' *.html)

do-install:
.for f in dshell dshell-decode
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}/${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/dshell
.for f in decode.py pcapanon.py
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}/${PREFIX}/libexec/dshell
.endfor
	(cd ${STAGEDIR}/${PREFIX}/libexec/dshell; \
		${LN} -sf decode.py decode)
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/dshell
	${INSTALL_DATA} ${WRKSRC}/.dshellrc ${STAGEDIR}/${PREFIX}/etc/dshell
	(cd ${WRKSRC}/lib; ${COPYTREE_SHARE} . ${STAGEDIR}/${PYTHON_SITELIBDIR}/dshell)
	(cd ${WRKSRC}/decoders; ${COPYTREE_SHARE} . ${STAGEDIR}/${PYTHON_SITELIBDIR}/dshell/decoders)
	${MKDIR} ${STAGEDIR}/${DATADIR}/GeoIP

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR} "-name *\.html")

.include <bsd.port.mk>
