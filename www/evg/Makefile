# New ports collection makefile for:	evg
# Date created:		19 April 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	evg
PORTVERSION=	1.3.1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.zurich.ibm.com//pub/sob/www/halloween/ \
		http://www.chg.ru/~dima/
DISTNAME=	evg-1_3_1
EXTRACT_SUFX=	_tar

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Create index pages in HTML for photo galleries

RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	xv:${PORTSDIR}/graphics/xv

USE_PERL5_BUILD=yes
USE_PYTHON=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}

post-patch:
	@ ${PERL} -pi -e 's#/usr/bin/python#${PYTHON_CMD}# ; \
		s#/usr/X11R6#${X11BASE}# ; \
		s#/usr/bin/ee#${X11BASE}/bin/xv#' ${WRKSRC}/evg

do-install:
	@ ${MKDIR} ${PYTHON_SITELIBDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/eclipthtml.py ${PYTHON_SITELIBDIR}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/evg ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/evg
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
