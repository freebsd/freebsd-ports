# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	arm
DISTVERSION=	1.4.5.0
CATEGORIES=	security net python
MASTER_SITES=	https://archive.torproject.org/arm/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Terminal status monitor for Tor

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
PORTDOCS=	armrc.sample

OPTIONS_DEFINE=	TOR \
		DOCS

OPTIONS_DEFAULT=TOR DOCS

TOR_DESC=	Enable local tor support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOR}
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof \
		tor:${PORTSDIR}/security/tor
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's,/usr/share/doc,${PREFIX}/share/doc,g' \
		${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} -e 's,/usr/share/doc/,${WRKSRC}/src,g' \
		${WRKSRC}/setup.py
.endif

	@${REINPLACE_CMD} -e 's,/usr/bin,${PREFIX}/bin,g' \
 		${WRKSRC}/arm ${WRKSRC}/setup.py ${WRKSRC}/src/uninstall
	@${REINPLACE_CMD} -e 's,/usr/share/man/man1,${PREFIX}/man/man1,g' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,/usr/share,${PYTHON_SITELIBDIR},g' \
 		${WRKSRC}/arm ${WRKSRC}/setup.py ${WRKSRC}/src/uninstall \
		${WRKSRC}/src/gui/controller.py

.include <bsd.port.post.mk>
