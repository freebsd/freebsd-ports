# New ports collection makefile for:	mmv
# Date created:		2 Feb 1995
# Whom:			Michael Elbel (me)
#
# $FreeBSD$
#

PORTNAME=	mmv
PORTVERSION=	1.01b
CATEGORIES=	misc
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.unix/volume21/mmv/
DISTFILES=	part01.Z part02.Z

PATCH_SITES=			ftp://gatekeeper.dec.com/pub/usenet/comp.sources.unix/volume22/
PATCHFILES=	mmv.pch.Z

MAINTAINER=	me@FreeBSD.org

NO_CDROM=	"No redistribution for charge"
NO_PACKAGE=	"No modification"
DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes
PATCH_DIST_ARGS=	-d ${WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP} mmv.c
MAN1=		mmv.1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}/tmp
	@(for file in ${DISTFILES}; do \
		${CP} ${DISTDIR}/${DIST_SUBDIR}/$$file ${WRKDIR}/tmp; \
	 done ; \
	 uncompress ${WRKDIR}/tmp/*; \
	 cd ${WRKDIR}; \
	 for file in tmp/part0* ; do \
	     ${SH} ${SCRIPTDIR}/unshar $$file; \
	 done ; \
	 ${CAT} mmv.c.? >mmv.c ; ${RM} mmv.c.? )

do-install:
	(cd ${PREFIX}/bin ; ${RM} -f mmv mad mcp mln ; \
	 ${INSTALL_PROGRAM} ${WRKSRC}/mmv ${PREFIX}/bin ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mad ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mcp ; \
	 ${LN} -fs ${PREFIX}/bin/mmv ${PREFIX}/bin/mln ; \
	 ${INSTALL_MAN} ${WRKSRC}/mmv.1 ${PREFIX}/man/man1 ; )

.include <bsd.port.mk>
