# New ports collection makefile for:	archmage
# Date created:                		22 February 2005
# Whom:                    		Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	archmage
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	archmage

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	Extensible reader/decompiler of files in CHM format

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib \
			 	install -c -O1 --prefix=${PREFIX}
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share,${PREFIX}/share," ${WRKSRC}/arch.conf
	@${REINPLACE_CMD} -e "s,/etc/arch\.conf,${PREFIX}/etc/arch\.conf," ${WRKSRC}/CHM.py
	@${MV} ${WRKSRC}/archmage ${WRKSRC}/archmage.orig
	@${MKDIR} ${WRKSRC}/archmage
	@${MV} ${WRKSRC}/archmage.orig ${WRKSRC}/archmage/archmage
	@${LN} -s ${WRKSRC}/chmlib/chmlib.py ${WRKSRC}/archmage/
	@${MV} ${WRKSRC}/CHM.py ${WRKSRC}/archmage/
	@${MV} ${WRKSRC}/mod_chm.py ${WRKSRC}/archmage/

post-install:
	@${ECHO} "archmage" > ${PYTHON_SITELIBDIR}/archmage.pth

.include <bsd.port.post.mk>
