# Created by: ijliao
# $FreeBSD$

PORTNAME=	sgrep
PORTVERSION=	1.1a
PORTEPOCH=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://www.rexx.com/~dkuhlman/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pysgrep-${PORTVERSION}.tar.gz sgrep-${SGREP_VER}.tar.gz
EXTRACT_ONLY=	sgrep-${SGREP_VER}.tar.gz

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrappers for Sgrep

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/sgreplib.so
SGREP_VER=	1.94a
WRKSRC=		${WRKDIR}/sgrep-${SGREP_VER}
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pysgrep
PYDISTUTILS_PKGVERSION=	1.0a

NO_STAGE=	yes
post-extract:
	@${TAR} -zxf ${DISTDIR}/pysgrep-${PORTVERSION}.tar.gz -C ${WRKSRC}

.include <bsd.port.mk>
