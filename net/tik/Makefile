# New ports collection makefile for:	tik
# Date created:				13 January 1999
# Whom:					Eugene M. Kim <astralblue@usa.net>
#
# $FreeBSD$
#

PORTNAME=	tik
PORTVERSION=	0.89
CATEGORIES=	net tk82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tik

MAINTAINER=	dionysos@anti-aol.org

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tik
PLIST=		${WRKDIR}/PLIST

SORT?=		sort

SRCDIRS=	share/tik share/tik/components share/tik/media \
		share/tik/packages share/tik/strs

.include <bsd.port.pre.mk>
.include "${FILESDIR}/srcfiles"

EGDIR=		share/examples/tik
EGFILES=	example.tikstrs example.pkgrc
DOCDIR=		share/doc/tik
DOCFILES=	CHANGES CONTRIBUTORS COPYING LICENSE README-LANG \
		NEW-FEATURES TODO

# The packing list starts with just bin/tik.  As we install things,
# build onto the list.
do-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.for d in ${SRCDIRS}
	@${MKDIR} ${PREFIX}/${d}
	@${ECHO} @dirrm ${d} >> ${PLIST}.dirrm
.endfor
.for f in ${SRCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/tik/${f}
	@${ECHO} share/tik/${f} >> ${PLIST}
.endfor
	@${MKDIR} ${PREFIX}/${EGDIR}
	@${ECHO} @dirrm ${EGDIR} >> ${PLIST}.dirrm
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${EGDIR}/${f}
	@${ECHO} ${EGDIR}/${f} >> ${PLIST}
.endfor
	@${SED} 's#@PREFIX@#${PREFIX}#g' < ${FILESDIR}/tik >${WRKDIR}/tik.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tik.sh ${PREFIX}/bin/tik
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${ECHO} @dirrm ${DOCDIR} >> ${PLIST}.dirrm
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DOCDIR}/${f}
	@${ECHO} ${DOCDIR}/${f} >> ${PLIST}
.endfor
.endif
	@${SORT} -r ${PLIST}.dirrm >> ${PLIST} && ${RM} ${PLIST}.dirrm

.include <bsd.port.post.mk>
