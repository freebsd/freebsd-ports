# Created by: Sylvio Cesar <scjamorim@bsd.com.br>
# $FreeBSD$

PORTNAME=	lshell
PORTVERSION=	0.9.18.20160916
CATEGORIES=	shells

MAINTAINER=	dam@my.gd
COMMENT=	Shell environment to limited sets of commands to users

LICENSE=	GPLv3+

GH_ACCOUNT=	ghantoos
GH_PROJECT=	lshell
GH_TAGNAME=	279d7ab

NO_ARCH=	yes
USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils

post-patch:
	@${REINPLACE_CMD} -e \
		"s|(.*lshell.conf.*),|| ; \
		 s|/etc|etc| ; \
		 s|share/man|man| ; \
		 s|'COPYING',||" ${WRKSRC}/setup.py

post-install:
	(cd ${WRKSRC}/etc && ${INSTALL_DATA} ${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample)

.include <bsd.port.mk>
