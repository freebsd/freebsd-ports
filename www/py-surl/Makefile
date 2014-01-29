# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	surl
PORTVERSION=	0.7.1.1
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/96097348/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	URL shortening command line application

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e 's,share/man/man1,${PREFIX}/man/man1,g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
