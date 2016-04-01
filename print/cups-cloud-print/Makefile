# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	20140814.3
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cups-config:print/cups
RUN_DEPENDS=	cancel:print/cups \
		${PYTHON_PKGNAMEPREFIX}pycups>0:print/py-pycups \
		bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2

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
