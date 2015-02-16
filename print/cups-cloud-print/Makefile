# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	20140814.1
CATEGORIES=	print
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3

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
GH_COMMIT=	65d3bff

USES=		gmake python shebangfix
SHEBANG_FILES=	testing/*.sh
GNU_CONFIGURE=	yes
MAKE_ARGS=	NOPERMS=1

.include <bsd.port.mk>
