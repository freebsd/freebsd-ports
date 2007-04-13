# New ports collection makefile for:	fl0p
# Date created:		2006-12-04
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	fl0p
PORTVERSION=	0.0.2.b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/soft/
DISTNAME=	fl0p-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	trasz@freebsd.org
COMMENT=	Passive L7 flow fingerprinting tool

WRKSRC=		${WRKDIR}/fl0p/

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fl0p ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fl0p.fp ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/README ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/ChangeLog ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/TODO ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/CREDITS ${DOCSDIR}/
.endif

.include <bsd.port.mk>
