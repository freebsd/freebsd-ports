# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=		p0f
PORTVERSION=		2.0.1
CATEGORIES=		net
MASTER_SITES=		http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=		.tgz

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Passive OS fingerprinting tool

DOCFILES=		COPYING CREDITS KNOWN_BUGS README TODO winxp-memleak.txt
PLIST=			${WRKDIR}/pkg-plist
WRKSRC=			${WRKDIR}/p0f

post-patch:
.for ii in config.h doc/README
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${SED} -e "s=/etc=${PREFIX}/etc=g" < ${WRKSRC}/${ii}.orig > \
		${WRKSRC}/${ii}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/p0frep ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${ii} ${DOCSDIR}
.endfor
.endif

pre-install:
	${ECHO_CMD} bin/p0f	> ${PLIST}
	${ECHO_CMD} bin/p0frep	>> ${PLIST}
	${ECHO_CMD} etc/p0f.fp	>> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO_CMD} share/doc/p0f/$i >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrm share/doc/p0f" >> ${PLIST}
.endif

.include <bsd.port.mk>
