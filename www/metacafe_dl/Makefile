# Created by: Fernando Durango <fernando@secret.org>
# $FreeBSD$

PORTNAME=	metacafe_dl
PORTVERSION=	2007.09.13
PORTREVISION=	2
CATEGORIES=	www
#MASTER_SITES=	http://www.arrakis.es/~rggi3/metacafe-dl/
DISTNAME=	metacafe-dl-${PORTVERSION}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for downloading videos from metacafe.com

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	yes

PLIST_FILES=	bin/metacafe-dl

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${DISTDIR}/metacafe-dl-${PORTVERSION} ${WRKSRC}/metacafe-dl

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' ${WRKSRC}/metacafe-dl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/metacafe-dl ${PREFIX}/bin

.include <bsd.port.post.mk>
