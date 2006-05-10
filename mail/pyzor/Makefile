# ex:ts=8
# Ports collection makefile for:	pyzor
# Date created:			Aug 1, 2002
# Whom:                 	ijliao
#
# $FreeBSD$
#

PORTNAME=	pyzor
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collaborative, networked system to detect and block spam

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	${REINPLACE_CMD} -e "s,/usr/bin/python2,${PYTHON_CMD}," \
		${WRKSRC}/scripts/pyzor ${WRKSRC}/scripts/pyzord

post-install:
	${CHMOD} ${SHAREMODE} ${DOCSDIR}/usage.html
	${CHMOD} ${BINMODE} ${PREFIX}/bin/pyzor ${PREFIX}/bin/pyzord

.include <bsd.port.mk>
