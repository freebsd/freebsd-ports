# ex:ts=8
# Ports collection makefile for:	latex2slides
# Date created:			May 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	latex2slides
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produces a set of HTML/JPEG slides from a TeX or LaTeX source

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/teTeX \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTNAME="${PORTNAME}" PORTVERSION="${PORTVERSION}"

MANCOMPRESSED=	yes
MAN1=		latex2slides.1

post-patch:
.for file in install latex2slides
	@${REINPLACE_CMD} -e "s,'/usr/bin/,'${PREFIX}/bin/,g ; \
		 s,'/usr/share/latex2slides/,'${DATADIR}/,g ; \
		 s,'/usr/share/man/,'${MANPREFIX}/man/,g" ${WRKSRC}/${file}
.endfor

do-install:
	@(cd ${WRKSRC} ; ${PYTHON_CMD} ./install)

.include <bsd.port.mk>
