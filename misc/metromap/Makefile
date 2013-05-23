# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	metromap
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://metromap.antex.ru/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A simple application for finding paths in different subways maps

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		gettext

PORTDOCS=	AUTHORS NEWS README README.data TODO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,make,${GMAKE},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${SETENV} python,' ${WRKSRC}/metromap.py
	@${RM} -f ${WRKSRC}/modules/ReadMap.py.orig

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
