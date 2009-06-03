# Ports collection Makefile for:   pcs
# Date created:        15 July 2006
# Whom:                gnn
#
# $FreeBSD$
#

PORTNAME=	pcs
PORTVERSION=	0.5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pcs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Protocol Construction Set

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800074
BROKEN=		does not build
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in pcs.pdf
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for f in arpwhohas.py ddos_analyze.py dns_query.py http_get.py \
		pcap_info.py pcap_slice.py ping.py snarf.py udp_echo.py
	${INSTALL_DATA} ${WRKSRC}/scripts/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
