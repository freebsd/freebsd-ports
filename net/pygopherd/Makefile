# ex:ts=8
# Ports collection makefile for:	pygopherd
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pygopherd
PORTVERSION=	1.1.0
CATEGORIES=	net python
MASTER_SITES=	http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Multiprotocol Information Server

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN8=	pygopherd.8

post-patch:
.for file in setup.py bin/pygopherd conf/pygopherd.conf pygopherd.8
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s|/usr/bin/python2.2|${SETENV} python|g" \
		${WRKSRC}/bin/pygopherd
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/bin/python2.2|${SETENV} python|g"

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8

.include <bsd.port.mk>
