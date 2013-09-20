# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	brebis
PORTVERSION=	0.6
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://brebisproject.org/attachments/download/7/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Fully automated backup checker

LICENSE=	GPLv3

USE_PYTHON=	3.3+
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

MAN1=	brebis.1
MANCOMPRESSED=	no
PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s|'share','man'|'${MANPREFIX}/man'|" ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
