# ex:ts=8
# New ports collection makefile for:	lfm
# Date created:			Jul 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfm
PORTVERSION=	0.91
CATEGORIES=	sysutils
MASTER_SITES=	http://www.terra.es/personal7/inigoserna/lfm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Last File Manager, a simple 'commander'-type file manager

USE_PYTHON=	2.0+
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/DOC_FILES/d' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog NEWS README README.pyview TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
