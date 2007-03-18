# Ports collection Makefile for:   pcs
# Date created:        15 July 2006
# Whom:                gnn
#
# $FreeBSD$
#

PORTNAME=	pcs
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pcs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Protocol Construction Set

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/pcap.so:${PORTSDIR}/net/py-pypcap

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in design.pdf pcs.pdf
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for f in arpwhohas.py ddos_analyze.py dns_query.py http_get.py \
		ping.py snarf.py tcpslice.py udp_echo.py
	${INSTALL_DATA} ${WRKSRC}/scripts/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
