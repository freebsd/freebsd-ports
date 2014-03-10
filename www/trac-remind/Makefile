# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	remind
PORTVERSION=	1
PORTREVISION=	5
CATEGORIES=	www devel python
MASTER_SITES=	http://www.unixmedia.it/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trac tickets reminder script

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

NO_BUILD=	yes
USES=		zip
USE_PYTHON=	2

PLIST_FILES=	bin/tracremind.py etc/tracremind.conf

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		 -e "s,%%PYTHON%%,${PYTHON_CMD}," ${WRKSRC}/tracremind.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tracremind.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tracremind.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
