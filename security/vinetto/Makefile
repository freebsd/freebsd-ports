# Created by: Aleksander Fafula <alex@BSDGuru.org>

PORTNAME=	vinetto
PORTVERSION=	0.07
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-beta-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Forensics tool to examine Thumbs.db files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Obsolete, targets deprecated Windows operating systems such as XP and 2003 Server
EXPIRATION_DATE=2022-03-31

RUN_DEPENDS=	${PY_PILLOW}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent optsuffix
PYDISTUTILS_PKGVERSION=	0.06alpha
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinreport.py
	@${REINPLACE_CMD} -e "s|/usr/share/vinetto|${DATADIR}|g" ${WRKSRC}/vinetto

.include <bsd.port.mk>
