# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	20140814.2
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3

BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cups>=0:${PORTSDIR}/print/py-cups \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:${PORTSDIR}/www/py-httplib2 \
		bash:${PORTSDIR}/shells/bash \
		cancel:${PORTSDIR}/print/cups-base

CONFIGURE_ENV=	cupsgroup=cups
GNU_CONFIGURE=	yes
MAKE_ARGS=	NOPERMS=1
NO_ARCH=	yes
NO_BUILD=	yes
USES=		gmake python shebangfix

SHEBANG_FILES=	testing/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	simoncadman
GH_PROJECT=	CUPS-Cloud-Print

.include <bsd.port.mk>
