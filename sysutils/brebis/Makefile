# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	brebis
PORTVERSION=	0.8
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://brebisproject.org/attachments/download/9/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

LICENSE=	GPLv3

USE_PYTHON=	3.3+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
