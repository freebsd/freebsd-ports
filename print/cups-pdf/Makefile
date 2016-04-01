# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	cups-pdf
PORTVERSION=	2.6.1
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://www.cups-pdf.de/src/ \
		http://www.physik.uni-wuerzburg.de/~vrbehr/cups-pdf/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual printer for CUPS to produce PDF files

LICENSE=GPLv2
LICENSE_FILE=${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/sbin/cupsd:print/cups

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		ghostscript:run

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

SUBST_CMD=		-e "s,\#GhostScript /usr/bin/gs,GhostScript ${LOCALBASE}/bin/gs," \
			-e 's,\#GSTmp /var/tmp,GSTmp /tmp,' \
			-e 's,\#Grp lp,Grp daemon,' \
			-e 's,\#Spool /var/spool/cups-pdf/SPOOL,Spool /var/spool/cups-pdf,'

.ifdef(PDF_VERSION)
.if ${PDF_VERSION} == 1.2
.elif ${PDF_VERSION} == 1.3
.elif ${PDF_VERSION} == 1.4
.elif ${PDF_VERSION} == 1.5
.else
BROKEN=		Unsupported PDF-Version selected: ${PDF_VERSION}
.endif
SUBST_CMD+=	-e "s,\#PDFVer 1.4,PDFVer ${PDF_VERSION},"
.endif

.ifdef(HOME_SUBDIR)
SUBST_CMD+=	-e 's,\#Out /var/spool/cups-pdf/$${USER},Out $${HOME}/${HOME_SUBDIR},'
.else
.ifdef(OUTPUT_DIRECTORY)
SUBST_CMD+=	-e 's,\#Out /var/spool/cups-pdf/$${USER},Out ${OUTPUT_DIRECTORY},'
.endif
.endif

.ifdef(LOG_DIRECTORY)
SUBST_CMD+=	-e "s,\#Log /var/log/cups,Log ${LOG_DIRECTORY},"
.endif

pre-everything::
.if !defined(PDF_VERSION) || !defined(HOME_SUBDIR) || \
!defined(OUTPUT_DIRECTORY) || !defined(LOG_DIRECTORY)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
.endif
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
	@${REINPLACE_CMD} ${SUBST_CMD} ${WRKSRC}/extra/cups-pdf.conf
	@${REINPLACE_CMD} -e \
	's,CPCONFIG "/etc/cups/cups-pdf.conf",CPCONFIG "${PREFIX}/etc/cups/cups-pdf.conf",' \
	${WRKSRC}/src/cups-pdf.h

do-build:
	cd ${WRKSRC}/src; ${CC} ${CFLAGS} -o cups-pdf cups-pdf.c

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cups/backend
	${INSTALL} ${WRKSRC}/src/cups-pdf ${STAGEDIR}${PREFIX}/libexec/cups/backend
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/cups/backend/cups-pdf
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cups/model
	${INSTALL_DATA} ${WRKSRC}/extra/CUPS-PDF.ppd \
		${STAGEDIR}${PREFIX}/share/cups/model/CUPS-PDF.ppd
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cups
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/extra/cups-pdf.conf \
		${STAGEDIR}${PREFIX}/etc/cups/cups-pdf.conf.sample

.include <bsd.port.mk>
