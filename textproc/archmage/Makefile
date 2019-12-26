# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	archmage
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible reader/decompiler of files in CHM format

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chm/chm.py:textproc/pychm \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:www/py-beautifulsoup32@${PY_FLAVOR}

NO_BUILD=	yes
USES=		cpe python:2.7 tar:bzip2
USE_PYTHON=	distutils autoplist

CPE_VENDOR=	archmage_project

PLIST_FILES=	man/man1/archmage.1.gz

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share/archmage,${DATADIR}," ${WRKSRC}/arch.conf
	@${REINPLACE_CMD} -e "s,/etc/archmage,${ETCDIR}," ${WRKSRC}/archmod/__init__.py
	@${REINPLACE_CMD} -e "s,/etc/archmage,${ETCDIR},;/archmage.1/d; \
		s,share/archmage,${DATADIR_REL}," ${WRKSRC}/setup.py

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
