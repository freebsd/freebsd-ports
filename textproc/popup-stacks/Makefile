# $FreeBSD$

PORTNAME=	popup
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://popup.sourceforge.net/files/cstack/
PKGNAMESUFFIX=	-stacks${PKGNAMESUFFIX2}
DISTFILES=	English-German.cstack.gz German-French.cstack.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stacks for use with Popup

LICENSE=	GPLv2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

STACKS=		English-German.cstack German-French.cstack
.for i in ${STACKS}
PLIST_FILES+=	${EXAMPLESDIR}/${i}
.endfor

do-extract:
	${MKDIR} ${WRKDIR}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${i} ${WRKDIR}/
	${GZIP_CMD} -d ${WRKDIR}/${i}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd  ${WRKDIR} && ${INSTALL_DATA} ${STACKS} ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
