# New ports collection makefile for:  pcal
# Date created:               10 June 2001
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	pcal
PORTVERSION=	4.11.0
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript calendar program

MAKE_ENV=	HOST_CC="${CC}"
ALL_TARGET=
USE_GMAKE=	yes

MAN1=		pcal.1
PORTDOCS=	ReadMe.txt pcal.html pcalw.html

WWWSERVER!=	hostname

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/html/pcal.cgi
	@${REINPLACE_CMD} -e \
		's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/html/pcal.pl
	@${REINPLACE_CMD} -e \
		's|@@WWWSERVER@@|${WWWSERVER}|g' ${WRKSRC}/html/pcal.html
	@${REINPLACE_CMD} -e \
		's|@@WWWSERVER@@|${WWWSERVER}|g' ${WRKSRC}/html/pcalw.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exec/pcal ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/html/pcal.cgi ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/html/pcal.pl ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/doc/pcal.man ${MANPREFIX}/man/man1/pcal.1
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ReadMe.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/pcal.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/pcalw.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
