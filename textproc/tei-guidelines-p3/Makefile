# New ports collection makefile for:	tei-p3-guidelines
# Date created:				29 April 2002
# Whom:	      				Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p3
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Vault/GL/
PKGNAMESUFFIX=	-guidelines
.if !defined(WITHOUT_HTML)
DISTFILES+=	teip3html.tar.gz
.endif
.if !defined(WITHOUT_PDF)
DISTFILES+=	p4beta.pdf
.endif
.if !defined(WITHOUT_P3X)
DISTFILES+=	teip3p3x.tar.gz
.endif
# Separate DISTFILES and EXTRACT_ONLY to make portlint happy
.if !defined(WITHOUT_HTML)
EXTRACT_ONLY+=	teip3html.tar.gz
.endif
.if !defined(WITHOUT_PDF)
EXTRACT_ONLY+=	# Empty, needed for PDF-only install
.endif
.if !defined(WITHOUT_P3X)
EXTRACT_ONLY+=	teip3p3x.tar.gz
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TEI's Guidelines for Electronic Text Encoding and Interchange

LATEST_LINK=	tei-guidelines-p3
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
INSTDIR=	${PREFIX}/share/doc/tei/p3
.if !defined(WITHOUT_HTML)
PLIST_SUB+=	HTML=
.else
PLIST_SUB+=	HTML="@comment "
.endif
.if !defined(WITHOUT_PDF)
PLIST_SUB+=	PDF=
.else
PLIST_SUB+=	PDF="@comment "
.endif
.if !defined(WITHOUT_P3X)
PLIST_SUB+=	P3X=
.else
PLIST_SUB+=	P3X="@comment "
.endif

do-install:
	@${MKDIR} ${INSTDIR}
.if !defined(WITHOUT_HTML)
	@${MKDIR} ${INSTDIR}/html
	@${MKDIR} ${INSTDIR}/html/Figures
	@${MKDIR} ${INSTDIR}/html/ref
	@${INSTALL_MAN} ${WRKSRC}/*.htm ${INSTDIR}/html
	@${INSTALL_MAN} ${WRKSRC}/Figures/* ${INSTDIR}/html/Figures
	@${INSTALL_MAN} ${WRKSRC}/ref/* ${INSTDIR}/html/ref
.endif
.if !defined(WITHOUT_PDF)
	@${MKDIR} ${INSTDIR}/pdf
	@${INSTALL_MAN} ${DISTDIR}/p4beta.pdf ${INSTDIR}/pdf
.endif
.if !defined(WITHOUT_P3X)
	@${MKDIR} ${INSTDIR}/p3x
	@${INSTALL_MAN} ${WRKSRC}/P3X/* ${INSTDIR}/p3x
.endif

.include <bsd.port.mk>
