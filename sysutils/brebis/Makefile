# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	brebis
PORTVERSION=	0.9
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://brebisproject.org/attachments/download/18/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

LICENSE=	GPLv3

USES=	python:3.3+
USE_PYTHON=	distutils noegginfo

# XXX Handle UTF-8 '(c)' character within setup.py's header
MAKE_ENV+=	LC_ALL=en_US.UTF-8

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
