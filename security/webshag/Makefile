# $FreeBSD$

PORTNAME=	webshag
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.scrt.ch/outils/webshag/
DISTNAME=	ws110

MAINTAINER=	clutton@zoho.com
COMMENT=	Multi-threaded, multi-platform web server audit tool

LICENSE=	GPLv3

USES=		python:2.7 dos2unix
USE_PYTHON=distutils
PYSETUP=	setup.linux.py

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	NMAP WXGTK
OPTIONS_DEFAULT=NMAP
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNMAP}
BUILD_DEPENDS+=	${LOCALBASE}/bin/nmap:security/nmap
.endif

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.6+
WX_UNICODE=	yes
WX_COMPS=	python:run
.endif

post-patch:
	@${MV} ${WRKSRC}/config ${WRKSRC}/etc
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|g' \
		${WRKSRC}/webshag_cli.py
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|g' \
		${WRKSRC}/webshag_gui.py

do-install:
.if ${PORT_OPTIONS:MWXGTK}
	${INSTALL_SCRIPT} ${WRKSRC}/webshag_gui.py \
		${STAGEDIR}${PREFIX}/bin/webshag_gui
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/webshag_cli.py \
		${STAGEDIR}${PREFIX}/bin/webshag_cli
	@${INSTALL_DATA} ${WRKSRC}/etc/webshag.conf ${STAGEDIR}${PREFIX}/etc
	(cd ${WRKSRC}/database && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/webshag)
	(cd ${WRKSRC}/webshag && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PYTHON_SITELIBDIR}/webshag)

.include <bsd.port.mk>
