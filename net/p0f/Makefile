# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=		p0f
PORTVERSION=		2.0.2
CATEGORIES=		net
MASTER_SITES=		http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=		.tgz

MAINTAINER=		trevor@FreeBSD.org
COMMENT=		Passive OS fingerprinting tool

DOCFILES=	COPYING CREDITS ChangeLog KNOWN_BUGS README TODO win-memleak.txt
MAN1=		p0f.1
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
	${MKDIR} ${PREFIX}/etc/p0f
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc/p0f
	${INSTALL_MAN} ${WRKSRC}/p0f.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${ii} ${DOCSDIR}
.endfor
.endif

pre-install:
	${ECHO_CMD} bin/p0f	> ${PLIST}
	${ECHO_CMD} bin/p0frep	>> ${PLIST}
	${ECHO_CMD} etc/p0f/p0f.fp	>> ${PLIST}
	${ECHO_CMD} "@dirrm etc/p0f" >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCFILES}
	${ECHO_CMD} share/doc/p0f/$i >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrm share/doc/p0f" >> ${PLIST}
.endif

.include <bsd.port.mk>
