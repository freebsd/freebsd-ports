# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	archmage
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible reader/decompiler of files in CHM format

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chm/chm.py:${PORTSDIR}/textproc/pychm \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

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
