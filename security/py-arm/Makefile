# ports collection makefile for:	arm
# Date created:				20111019
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	arm
DISTVERSION=	1.4.4.0
CATEGORIES=	security net python
MASTER_SITES=	https://archive.torproject.org/arm/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	c-s@c-s.li
COMMENT=	A terminal status monitor for Tor

LICENSE=	GPLv3

RUN_DEPENDS=	lsof:${PORTSDIR}/sysutils/lsof \
		tor:${PORTSDIR}/security/tor

MAN1=		arm.1
MANCOMPRESSED=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=1.4.4
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
PORTDOCS=	armrc.sample

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's,/usr/share/doc/,${WRKSRC}/src,g' \
		${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} -e 's,/usr/share/doc,${PREFIX}/share/doc,g' \
		${WRKSRC}/setup.py
.endif

	@${REINPLACE_CMD} -e 's,/usr/bin,${PREFIX}/bin,g' \
 		${WRKSRC}/arm ${WRKSRC}/setup.py ${WRKSRC}/src/uninstall
	@${REINPLACE_CMD} -e 's,/usr/share/man/man1,${PREFIX}/man/man1,g' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's,/usr/share,${PYTHON_SITELIBDIR},g' \
 		${WRKSRC}/arm ${WRKSRC}/setup.py ${WRKSRC}/src/uninstall \
		${WRKSRC}/src/gui/controller.py

.include <bsd.port.mk>
