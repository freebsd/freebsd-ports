# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	pcal
PORTVERSION=	4.11.0
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript calendar program

USES=		shebangfix gmake tar:tgz

MAKE_ENV=	HOST_CC="${CC}"
ALL_TARGET=

PORTDOCS=	ReadMe.txt pcal.html pcalw.html
SHEBANG_FILES=	html/pcal.pl

WWWSERVER!=	hostname

OPTIONS_DEFINE=	DOCS EXAMPLES

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
	${INSTALL_PROGRAM} ${WRKSRC}/exec/pcal ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/html/pcal.cgi ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/html/pcal.pl ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/doc/pcal.man \
		${STAGEDIR}${MANPREFIX}/man/man1/pcal.1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ReadMe.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/pcal.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/pcalw.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
