# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	dissembler
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://www.l0t3k.net/tools/ShellCode/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	Tool that polymorphs bytecode to a printable ASCII string

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_FILES=bin/${PORTNAME}
PORTDOCS=	${PORTNAME}.txt

BROKEN=	checksum mismatch

NO_STAGE=	yes
do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.txt ${DOCSDIR}
.	endif

.include <bsd.port.mk>
