# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	cups-pdf
DISTVERSION=	3.0.1
CATEGORIES=	print
MASTER_SITES=	http://www.cups-pdf.de/src/ \
		http://www.physik.uni-wuerzburg.de/~vrbehr/cups-pdf/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual printer for CUPS to produce PDF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	${LOCALBASE}/sbin/cupsd:print/cups

USES=		ghostscript:run localbase

LIBS+=		-lcups

ETCDIR=		${PREFIX}/etc/cups

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

_SUBST_CMD=	-e "s,\#GhostScript /usr/bin/gs,GhostScript ${LOCALBASE}/bin/gs," \
		-e 's,\#GSTmp /var/tmp,GSTmp /tmp,' \
		-e 's,\#Grp lp,Grp daemon,' \
		-e 's,\#Spool /var/spool/cups-pdf/SPOOL,Spool /var/spool/cups-pdf,'

_PDF_VERSIONS=	1.2 1.3 1.4 1.5

.include <bsd.port.options.mk>

.ifdef(PDF_VERSION)
.if "${_PDF_VERSIONS:M${PDF_VERSION}}" == ""
BROKEN=		Unsupported PDF-Version selected: ${PDF_VERSION}
.endif
_SUBST_CMD+=	-e "s,\#PDFVer 1.4,PDFVer ${PDF_VERSION},"
.endif

.ifdef(HOME_SUBDIR)
_SUBST_CMD+=	-e 's,\#Out /var/spool/cups-pdf/$${USER},Out $${HOME}/${HOME_SUBDIR},'
.elifdef(OUTPUT_DIRECTORY)
_SUBST_CMD+=	-e 's,\#Out /var/spool/cups-pdf/$${USER},Out ${OUTPUT_DIRECTORY},'
.endif

.ifdef(LOG_DIRECTORY)
_SUBST_CMD+=	-e "s,\#Log /var/log/cups,Log ${LOG_DIRECTORY},"
.endif

pre-everything::
.if !defined(PDF_VERSION) || !defined(HOME_SUBDIR) || \
!defined(OUTPUT_DIRECTORY) || !defined(LOG_DIRECTORY)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
.endif
.if !defined(PDF_VERSION)
	@${ECHO_MSG} "PDF_VERSION=${_PDF_VERSIONS:S/ /|/Wg}   PDF-version of PDF-files produced"
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
	@${REINPLACE_CMD} ${_SUBST_CMD} ${WRKSRC}/extra/cups-pdf.conf
	@${REINPLACE_CMD} -e \
		's,CPCONFIG "/etc/cups/cups-pdf.conf",CPCONFIG "${ETCDIR}/cups-pdf.conf",' \
		${WRKSRC}/src/cups-pdf.h

do-build:
	(cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -o cups-pdf cups-pdf.c)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cups/backend
	${INSTALL_PROGRAM} ${WRKSRC}/src/cups-pdf \
		${STAGEDIR}${PREFIX}/libexec/cups/backend/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model
	${INSTALL_DATA} ${WRKSRC}/extra/CUPS-PDF_opt.ppd \
		${WRKSRC}/extra/CUPS-PDF_noopt.ppd \
		${STAGEDIR}${PREFIX}/share/cups/model/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/cups-pdf.conf \
		${STAGEDIR}${ETCDIR}/cups-pdf.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
