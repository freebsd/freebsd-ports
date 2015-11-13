# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	20140814.3
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	cancel:${PORTSDIR}/print/cups-base \
		${PYTHON_PKGNAMEPREFIX}cups>0:${PORTSDIR}/print/py-cups \
		bash:${PORTSDIR}/shells/bash \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	simoncadman
GH_PROJECT=	CUPS-Cloud-Print

USES=		gmake python shebangfix
SHEBANG_FILES=	testing/*.sh
GNU_CONFIGURE=	yes
MAKE_ARGS=	NOPERMS=1

DATADIR=	${PREFIX}/share/cloudprint-cups
DOCSDIR=	${PREFIX}/share/doc/cloudprint-cups

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/README.md/s|^|#| ; \
		 /COPYING/s|^|#|' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
