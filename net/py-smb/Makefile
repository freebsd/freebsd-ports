# ex:ts=8
# Ports collection makefile for:	pysmb
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	smb
PORTVERSION=	0.4.2
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/projects/pysmb/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysmb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/pysmb
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/py-smb
DOCSDIR=	${PREFIX}/share/doc/py-smb

do-install:
.for file in nmb.py smb.py
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor
.for file in nmbquery smbcp smbdu smblistshare
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/extra/*.reg ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/README ${DOCSDIR}
	${CP} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.gif ${DOCSDIR}
.endif

.include <bsd.port.mk>
