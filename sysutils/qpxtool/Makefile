# New ports collection makefile for:	qpxtool
# Date created:		23 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	qpxtool
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A GUI for testing CD/DVD quality and transfer rate

USE_BZIP2=	yes
USE_QT_VER=	3

USE_SCONS=	yes
SCONS_BUILDENV=	QTDIR="${QT_PREFIX}" TMPDIR="${TMPDIR}" ${SCONS_ENV}

USE_LDCONFIG=	yes

PORTDOCS=	README ChangeLog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/lib/* ${PREFIX}/lib/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
