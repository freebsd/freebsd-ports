# New ports collection makefile for:	archmage
# Date created:				22 February 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	archmage
PORTVERSION=	0.0.7
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Extensible reader/decompiler of files in CHM format

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chm/chm.py:${PORTSDIR}/textproc/pychm

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share,${PREFIX}/share," ${WRKSRC}/arch.conf
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc," ${WRKSRC}/archmod/CHM.py
	@${REINPLACE_CMD} -e "s,/etc,etc," ${WRKSRC}/setup.py

.include <bsd.port.mk>
