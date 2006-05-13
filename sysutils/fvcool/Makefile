# New ports collection makefile for:	fvcool
# Date created:				5 October 2002
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	fvcool
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/ \
		http://www.infracaninophile.co.uk/fvcool/
DISTNAME=	FVCool${PORTVERSION:S/.//g}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	VCool for FreeBSD - Cooling software for AMD Athlon/Duron CPUs

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes
ALL_TARGET=	fvcool
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,^${PREFIX}/,,}
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SED_SCRIPT=	-e 's,%%RC_SUBR%%,${RC_SUBR},g'   \
		-e 's,%%PORTNAME%%,${PORTNAME},g' \
		-e 's,%%PREFIX%%,${PREFIX},g'

PORTDOCS=	ReadMe ReadMe.jp ReadMe.tech_KT133
PLIST_FILES=	sbin/fvcool etc/rc.d/fvcool.sh

post-patch:
	@${REINPLACE_CMD} -e 's|@CC@|& ${CFLAGS}|; \
		s|-O3||g ; s| -s | |g' ${BUILD_WRKSRC}/Makefile.in

post-build:
	@${SED} ${SED_SCRIPT} ${SCRIPTDIR}/${PORTNAME}.sh \
	    > ${WRKDIR}/${PORTNAME}.sh
	@${SED} ${SED_SCRIPT} ${MSG_FILE} \
	    > ${PKGMESSAGE}

do-install: install-doc
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${PREFIX}/sbin/fvcool

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
	    ${PREFIX}/etc/rc.d/${PORTNAME}.sh
	@${CAT} ${PKGMESSAGE}

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
