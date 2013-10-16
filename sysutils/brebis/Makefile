# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	brebis
PORTVERSION=	0.7
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://brebisproject.org/attachments/download/8/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

LICENSE=	GPLv3

USE_PYTHON=	3.3+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

PORTDOCS=	README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
