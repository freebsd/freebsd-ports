# Created by: ijliao
# $FreeBSD$

PORTNAME=	pybook
PORTVERSION=	0.8c
CATEGORIES=	textproc python
MASTER_SITES=	http://silmarill.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Project Gutenberg e-texts reader

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,python2,python,g" ${WRKSRC}/pybook.py

post-install:
	@${MV} -f ${PREFIX}/bin/pybook.py ${PREFIX}/bin/pybook
	${MKDIR} ${PREFIX}/share/pybook
	${INSTALL_DATA} ${WRKSRC}/booklist ${PREFIX}/share/pybook/
	${INSTALL_DATA} ${WRKSRC}/vimrc ${PREFIX}/share/pybook/

.include <bsd.port.mk>
