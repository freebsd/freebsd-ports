# New ports collection makefile for:	cups-pdf
# Date created:		Jun 15 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	cups-pdf
PORTVERSION=	1.7.0
CATEGORIES=	print
MASTER_SITES=	http://cip.physik.uni-wuerzburg.de/~vrbehr/cups-pdf/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	A virtual printer for CUPS to produce PDF files

RUN_DEPENDS=	${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

USE_REINPLACE=	yes
USE_GHOSTSCRIPT_RUN=	yes

SUBST_CMD=		-e "s,/usr/bin/gs,${LOCALBASE}/bin/gs," \
			-e 's,/var/tmp,/tmp,' \
			-e 's,"lp","daemon",' \
			-e 's,/var/spool/cups-pdf/SPOOL,/var/spool/cups-pdf,'

.ifdef(PDF_VERSION)
.if ${PDF_VERSION} == 1.2
.elif ${PDF_VERSION} == 1.3
.elif ${PDF_VERSION} == 1.4
.elif ${PDF_VERSION} == 1.5
.else
BROKEN=		"unsupported PDF-Version selected: ${PDF_VERSION}"
.endif
SUBST_CMD+=	-e 's,CPPDFVER "1.4",CPPDFVER "${PDF_VERSION}",'
.endif

.ifdef(HOME_SUBDIR)
SUBST_CMD+=	-e 's,CPOUT "/var/spool/cups-pdf",CPOUT "$$HOME",' -e 's,CPHOMESUB "cups-pdf",CPHOMESUB "${HOME_SUBDIR}",'
.else
.ifdef(OUTPUT_DIRECTORY)
SUBST_CMD+=	-e 's,CPOUT "/var/spool/cups-pdf",CPOUT "${OUTPUT_DIRECTORY}",'
.endif
.endif

.ifdef(LOG_DIRECTORY)
SUBST_CMD+=	-e "s,/var/log/cups,${LOG_DIRECTORY},"
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
.if !defined(PDF_VERSION)
	@${ECHO_MSG} "PDF_VERSION=1.2|1.3|1.4|1.5   PDF-version of PDF-files produced"
.endif
.if !defined(HOME_SUBDIR)
	@${ECHO_MSG} "HOME_SUBDIR=<subdir>          Place produced PDF-files in the"
	@${ECHO_MSG} "                              directory ~/<subdir>/"
.endif
.if !defined(OUTPUT_DIRECTORY)
	@${ECHO_MSG} "OUTPUT_DIRECTORY=<dir>        Place produced PDF-files in the"
	@${ECHO_MSG} "                              directory <dir>/"
.endif
.if !defined(LOG_DIRECTORY)
	@${ECHO_MSG} "LOG_DIRECTORY=<dir>           Place logfile into <dir>/cups-pdf_log"
.endif

post-configure:
	@${REINPLACE_CMD} ${SUBST_CMD} ${WRKSRC}/src/cups-pdf.h
	@${GUNZIP_CMD} ${WRKSRC}/extra/PostscriptColor.ppd.gz

do-build:
	cd ${WRKSRC}/src; ${CC} ${CFLAGS} -o cups-pdf cups-pdf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cups-pdf ${LOCALBASE}/libexec/cups/backend
	${INSTALL_DATA} ${WRKSRC}/extra/PostscriptColor.ppd ${LOCALBASE}/share/cups/model
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
