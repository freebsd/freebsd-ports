# Created by: Aleksander Fafula <alex@BSDGuru.org>
# $FreeBSD$

PORTNAME=	vinetto
PORTVERSION=	0.07
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-beta-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Forensics tool to examine Thumbs.db files

OPTIONS_DEFINE=	THUMBNAILS
OPTIONS_DEFAULT=THUMBNAILS
IMAGING_DESC=	Build with ability to extract graphic thumbnails

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	0.06alpha

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGING}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow
.endif

do-patch:
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinreport.py
	${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinetto

.include <bsd.port.mk>
