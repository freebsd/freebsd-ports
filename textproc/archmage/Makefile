# New ports collection makefile for:	archmage
# Date created:                		22 February 2005
# Whom:                    		Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	archmage
PORTVERSION=	0.0.6
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archmage

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	Extensible reader/decompiler of files in CHM format

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib \
			 	install -c -O1 --prefix=${PREFIX}
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share,${PREFIX}/share," ${WRKSRC}/arch.conf
	@${REINPLACE_CMD} -e "s,/etc/arch\.conf,${PREFIX}/etc/arch\.conf," ${WRKSRC}/CHM.py

.include <bsd.port.mk>
