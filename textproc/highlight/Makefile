# New ports collection makefile for:	highlight
# Date created:				05 August 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlight
PORTVERSION=	2.0d7	#someday, people will stick to numbers and decimal points
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/d/-/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable syntax highlighter

WRKSRC=		${WRKDIR}/${PORTNAME}2

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.if !defined(NOPORTDOCS)
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/highlight|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}/datadir.cpp

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET}
	${MKDIR} ${DATADIR} ${EXAMPLESDIR} ${DOCSDIR}
	${MKDIR} ${DATADIR}/helpmsg ${DATADIR}/langDefs ${DATADIR}/themes
	${INSTALL_DATA} ${WRKSRC}/helpmsg/* ${DATADIR}/helpmsg
	${INSTALL_DATA} ${WRKSRC}/langDefs/*.lang ${DATADIR}/langDefs
	${INSTALL_DATA} ${WRKSRC}/langDefs/extensions.conf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/themes/* ${DATADIR}/themes
	${INSTALL_DATA} ${WRKSRC}/cgi/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1}.gz ${MANPREFIX}/man/man1
.for i in AUTHORS README ChangeLog COPYING INSTALL
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>
