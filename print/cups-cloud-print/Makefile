# $FreeBSD$

PORTNAME=	cups-cloud-print
PORTVERSION=	0.0.1
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print using Google Cloud Print

LICENSE=	GPLv3

BUILD_DEPENDS=	cancel:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cups>=0:${PORTSDIR}/print/py-cups \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:${PORTSDIR}/www/py-httplib2 \
		cancel:${PORTSDIR}/print/cups-base

USE_GITHUB=	yes
GH_ACCOUNT=	simoncadman
GH_PROJECT=	CUPS-Cloud-Print
GH_COMMIT=	d7ce53b
GH_TAGNAME=	${GH_COMMIT}

HAS_CONFIGURE=	yes

USES=	gmake python shebangfix
SHEBANG_FILES=	full-test.sh

#CONFIGURE_ARGS=	--cupsgroup=cups
MAKE_ARGS=	NOPERMS=1

.include <bsd.port.mk>
