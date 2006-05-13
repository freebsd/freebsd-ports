# ex:ts=8
# Ports collection makefile for:	pybook
# Date created:			Jan 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pybook
PORTVERSION=	0.8c
CATEGORIES=	textproc python
MASTER_SITES=	http://silmarill.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Project Gutenberg e-texts reader

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,python2,python,g" ${WRKSRC}/pybook.py

post-install:
	@${MV} -f ${PREFIX}/bin/pybook.py ${PREFIX}/bin/pybook
	${MKDIR} ${PREFIX}/share/pybook
	${INSTALL_DATA} ${WRKSRC}/booklist ${PREFIX}/share/pybook/
	${INSTALL_DATA} ${WRKSRC}/vimrc ${PREFIX}/share/pybook/

.include <bsd.port.mk>
