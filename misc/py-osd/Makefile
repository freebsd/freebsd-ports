# New ports collection makefile for: py-osd
# Date created:		08 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	osd
PORTVERSION=	0.2.11
CATEGORIES=	misc python
MASTER_SITES=	http://repose.cx/pyosd/ \
		http://damien.kangaweb.com/moving/stuff/pyosd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyosd-${PORTVERSION}

MAINTAINER=	sg-sendpr@waset.de
COMMENT=	A python wrapper for osd, for displaying text on your X display

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd
RUN_DEPENDS=	${LOCALBASE}/bin/twistd:${PORTSDIR}/devel/py-twisted

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

post-patch:
		${REINPLACE_CMD} -e 's;_X11BASE_;${X11BASE};g' ${WRKSRC}/setup.py

post-extract:
		@${MV} ${WRKSRC}/pyosd ${WRKSRC}/osd

.include <bsd.port.mk>
