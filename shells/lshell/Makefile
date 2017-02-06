# Created by: Sylvio Cesar <scjamorim@bsd.com.br>
# $FreeBSD$

PORTNAME=	lshell
PORTVERSION=	0.9.18.20160916
CATEGORIES=	shells
DISTNAME=	${PORTNAME}_0.9.18

MAINTAINER=	dam@my.gd
COMMENT=	Shell environment to limited sets of commands to users

LICENSE=	GPLv3+

GH_ACCOUNT=	ghantoos
GH_PROJECT=	lshell
GH_TAGNAME=	279d7ab

WRKSRC=		${WRKDIR}/${PORTNAME}-${GH_TAGNAME}

NO_ARCH=	yes
USES=		python
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
