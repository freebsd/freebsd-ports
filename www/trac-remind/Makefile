# New ports collection makefile for: trac-remind
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	remind
PORTVERSION=	1
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.unixmedia.it/
PKGNAMEPREFIX=	trac-
DISTNAME=	trac${PORTNAME}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Trac tickets reminder script

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

NO_BUILD=	yes
USE_ZIP=	yes
USE_PYTHON=	2.5+

PLIST_FILES=	bin/tracremind.py etc/tracremind.conf

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		 -e "s,%%PYTHON%%,${PYTHON_CMD}," ${WRKSRC}/tracremind.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tracremind.py ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tracremind.conf ${PREFIX}/etc

.include <bsd.port.mk>
