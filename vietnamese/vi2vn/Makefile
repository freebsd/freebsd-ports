# ex:ts=8
# Ports collection makefile for:  vi2vn
# Date created:		Monday, Nov 11, 2002
# Whom:			David O'Brien (obrien@NUXI.org)
#
# $FreeBSD$
#

PORTNAME=	vi2vn
PORTVERSION=	0.64
CATEGORIES=	vietnamese
MASTER_SITES=	http://linux.nguyendai.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Perl script to convert VIQR encoding to other Vietnamese encodings.

PORTCOMMENT=	Converts Vietnamese VIQR text into troff format

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

EXTRACT_CMD=		rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|${CPIO} -idum
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
NO_BUILD=	yes
MAN1=		${PORTNAME}.1

post-extract:
	@if ! (cd ${WRKDIR} && ${GZIP_CMD} -dc vi2vn.tgz | ${TAR} -xf -);\
		then exit 1; fi

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|g' ${WRKSRC}/${PORTNAME}*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.lib ${PREFIX}/share/${PORTNAME}
	${CP} -R ${WRKSRC}/enc ${PREFIX}/share/${PORTNAME}

post-install:
	@cd ${PREFIX} ;\
	    ${FIND} share/${PORTNAME} -type f -o -type l >${WRKDIR}/PLIST.share
	@cd ${PREFIX} ;\
	    ${FIND} share/${PORTNAME} -type d \
	    	| ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.share
	@${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	@${ECHO_CMD} "/Insert PLIST.share"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/PLIST.share"	>> ${WRKDIR}/ex.script
	@${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share
	@cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
