PORTNAME=	gvm
PORTVERSION=	22.4.0
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone vulnerability management (metaport)

USES=		metaport python:3.7+

# Install GVM libraries
RUN_DEPENDS+=	${LOCALBASE}/lib/libgvm_base.so:security/gvm-libs

# Install GVM Manager
RUN_DEPENDS+=	${LOCALBASE}/sbin/gvmd:security/gvmd

# Install Scanner wrapper for OSP
RUN_DEPENDS+=	${LOCALBASE}/bin/ospd-openvas:security/py-ospd-openvas@${PY_FLAVOR}

# Install OpenVAS Scanner
RUN_DEPENDS+=   ${LOCALBASE}/sbin/openvas:security/openvas

# Install Notus Scanner
RUN_DEPENDS+=	${LOCALBASE}/bin/notus-scanner:security/py-notus-scanner

# Install GVM Web Interface
RUN_DEPENDS+=	${LOCALBASE}/sbin/gsad:security/gsad
RUN_DEPENDS+=	${LOCALBASE}/share/gvm/gsad/web/index.html:security/gsa

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		PYTHON-GVM GVM-TOOLS
OPTIONS_DEFAULT=	PYTHON-GVM GVM-TOOLS

PYTHON-GVM_DESC=	Install GVM python API library
GVM-TOOLS_DESC=		Install GVM tools

PYTHON-GVM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gvm>=0:security/py-python-gvm@${PY_FLAVOR}
GVM-TOOLS_RUN_DEPENDS=	gvm-cli:security/py-gvm-tools@${PY_FLAVOR}

.include <bsd.port.mk>
