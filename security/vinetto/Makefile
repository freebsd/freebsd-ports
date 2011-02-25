# New ports collection makefile for:	vinetto
# Date created:		2006-12-26
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$
#

PORTNAME=	vinetto
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-beta-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A forensics tool to examine Thumbs.db files

OPTIONS=	IMAGING "Build with ability to extract graphic thumbnails" on

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=	0.06alpha

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAGING)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
.endif

do-patch:
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinreport.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinetto

.include <bsd.port.post.mk>
