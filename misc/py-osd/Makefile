# New ports collection makefile for: py-osd
# Date created:		08 Aug 2003
# Whom:			larse@isi.edu
#
# $FreeBSD$
#

PORTNAME=	osd
PORTVERSION=	0.2.14
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	http://repose.cx/pyosd/ \
		http://damien.kangaweb.com/moving/stuff/pyosd/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyosd-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A python wrapper for osd, for displaying text on your X display

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd
RUN_DEPENDS=	${LOCALBASE}/bin/twistd:${PORTSDIR}/devel/py-twisted

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	AUTHORS ChangeLog ChangeLog.old README README.daemon pyosd.html
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
		@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
