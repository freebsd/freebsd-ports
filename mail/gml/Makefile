# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gml
PORTVERSION=	0.4
CATEGORIES=	mail
MASTER_SITES=	http://marklyon.org/wp-content/uploads/2013/01/ \
		LOCAL/glarkin
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mbox & Maildir to Gmail loader

USE_PYTHON_RUN=	2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		dos2unix
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|.exe||g' \
		-e 's|"c:\\mail\\Inbox.*"|/home/user/Inbox|g' ${WRKDIR}/*

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
