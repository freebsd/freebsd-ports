# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=		p0f
PORTVERSION=		1.8.2
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.stearns.org/p0f/
EXTRACT_SUFX=		.tgz

MAINTAINER=		trevor@FreeBSD.org

USE_REINPLACE=		yes
DOCFILES=		COPYING CREDITS ChangeLog README
MAN1=			p0f.1
PLIST=			${WRKDIR}/pkg-plist

post-patch:
	${REINPLACE_CMD} -e "s=/etc=${PREFIX}/etc=g" \
		${WRKSRC}/README \
		${WRKSRC}/p0f.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/p0frep ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

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

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/p0f
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/p0f
.endfor
.endif

.include <bsd.port.mk>
