# ex:ts=8
# Ports collection makefile for:	pysmb
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	smb
PORTVERSION=	0.3.1
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/projects/pysmb/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysmb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/pysmb
NO_BUILD=	yes

do-install:
.for file in nmb.py smb.py
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}
.endfor
.for file in nmbquery smbcp smbdu smblistshare
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/share/py-smb
	${CP} ${WRKSRC}/extra/*.reg ${PREFIX}/share/py-smb
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/py-smb
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/py-smb
	${CP} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.gif ${PREFIX}/share/doc/py-smb
.endif

.include <bsd.port.mk>
