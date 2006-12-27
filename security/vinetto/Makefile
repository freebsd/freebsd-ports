# New ports collection makefile for:	vinetto
# Date created:		2006-12-26
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$
#

PORTNAME=	vinetto
PORTVERSION=	0.06
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	alex@BSDGuru.org
COMMENT=	A forensics tool to examine Thumbs.db files

OPTIONS=	IMAGING "Build with ability to extract graphic thumbnails" on

USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAGING)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
.endif

do-patch:
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinreport.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinetto

.include <bsd.port.post.mk>
