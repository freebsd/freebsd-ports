# ex:ts=8
# New ports collection makefile for: 	py-sgrep
# Date created:			Jun 14, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sgrep
PORTVERSION=	${SGREP_VER}	# dont know ver, so I decide to choose sgrep ver
CATEGORIES=	textproc python
MASTER_SITES=	http://www.rexx.com/~dkuhlman/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pysgrep.tar.gz sgrep-${SGREP_VER}.tar.gz
EXTRACT_ONLY=	sgrep-1.92a.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrappers for Sgrep

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/sgreplib.so
SGREP_VER=	1.92a
WRKSRC=		${WRKDIR}/sgrep-${SGREP_VER}
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-extract:
	@${TAR} -zxf ${_DISTDIR}/pysgrep.tar.gz -C ${WRKSRC}

.include <bsd.port.mk>
