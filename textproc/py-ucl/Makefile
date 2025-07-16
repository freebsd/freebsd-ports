PORTNAME=	ucl
DISTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	UCL parser and emmitter
WWW=		https://github.com/vstakhov/libucl/

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/libucl-${PORTVERSION}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
	libucl.so:textproc/libucl

USES=		localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov
GH_PROJECT=	libucl
USE_PYTHON=	autoplist concurrent distutils

CPPFLAGS+=	-Iuthash

WRKSRC_SUBDIR=	python

.include <bsd.port.mk>
