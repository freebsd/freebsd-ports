# New ports collection makefile for:	py-fonttools
# Date created:				2 January 2001
# Whom:                 		Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fonttools
PORTVERSION=	1.0b1
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fonttools
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fonttools-${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org

BUILD_DEPENDS=	xmlproc_val:${PORTSDIR}/textproc/py-xml \
		${PYNUMERIC}
RUN_DEPENDS=	xmlproc_val:${PORTSDIR}/textproc/py-xml \
		${PYNUMERIC}

WRKSRC=		${WRKDIR}/fonttools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCDIR=		${PREFIX}/share/doc/py-fonttools

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ttDump.py ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/ttCompile.py ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/index.html ${DOCDIR}
.endif

.include <bsd.port.mk>
