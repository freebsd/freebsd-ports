# ex:ts=8
# Ports collection makefile for:	latex2slides
# Date created:			May 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	latex2slides
PORTVERSION=	0.8.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Produces a set of HTML/JPEG slides from a TeX or LaTeX source

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		dvips:${PORTSDIR}/print/teTeX \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_REINPLACE=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

MANCOMPRESSED=	yes
MAN1=	latex2slides.1

post-patch:
	@${REINPLACE_CMD} -e "s,/usr,${PREFIX},g ; \
		s,share/man,man,g" ${WRKSRC}/install
	@${REINPLACE_CMD} -e "s,/usr/share,${PREFIX}/share,g" ${WRKSRC}/latex2slides

do-install:
	@(cd ${WRKSRC} ; ${PYTHON_CMD} ./install)

.include <bsd.port.mk>
