# Created by: ijliao
# $FreeBSD$

PORTNAME=	pygopherd
PORTVERSION=	2.0.16
PORTREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/ \
		http://gopher.quux.org:70/devel/gopher/Downloads/pygopherd/old/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	neel@neelc.org
COMMENT=	Multiprotocol Information Server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_ARCH=	yes

post-patch:
.for f in setup.py bin/pygopherd conf/pygopherd.conf doc/pygopherd.8
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s|/usr/bin/python2.2|${PYTHON_CMD}|g" \
		${WRKSRC}/bin/pygopherd
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/bin/python2.2|${PYTHON_CMD}|g"
	@${MV} ${WRKSRC}/conf/pygopherd.conf ${WRKSRC}/conf/pygopherd.conf.sample

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pygopherd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
