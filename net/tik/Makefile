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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tcl/Tk based AOL Instant Messenger (AIM) Chat Client

RUN_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tik

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
.for d in ${SRCDIRS}
	@${MKDIR} ${PREFIX}/${d}
.endfor
.for f in ${SRCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/tik/${f}
.endfor
	@${MKDIR} ${PREFIX}/${EGDIR}
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${EGDIR}/${f}
.endfor
	@${SED} 's#@PREFIX@#${PREFIX}#g' < ${FILESDIR}/tik >${WRKDIR}/tik.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tik.sh ${PREFIX}/bin/tik
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DOCDIR}/${f}
.endfor
.endif

.include <bsd.port.post.mk>
