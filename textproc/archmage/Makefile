# New ports collection makefile for:	archmage
# Date created:				22 February 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	archmage
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible reader/decompiler of files in CHM format

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chm/chm.py:${PORTSDIR}/textproc/pychm \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAN1=	${PORTNAME}.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share/archmage,${DATADIR}," ${WRKSRC}/arch.conf
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc," ${WRKSRC}/archmod/CHM.py
	@${REINPLACE_CMD} -e "s,/etc,etc,;/archmage.1/d" ${WRKSRC}/setup.py

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
