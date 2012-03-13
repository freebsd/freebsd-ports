# Ports collection makefile for:	py-surl
# Date created:		2010-10-04
# Whom:			Carlo Strub <c-s@c-s.li>
#
# $FreeBSD$
#

PORTNAME=	surl
PORTVERSION=	0.7.1.1
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/96097348/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	URL shortening command line application

LICENSE=	GPLv3

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USE_BZIP2=	yes
MAN1=		surl.1

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 260
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,share/man/man1,${PREFIX}/man/man1,g' \
	                ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
