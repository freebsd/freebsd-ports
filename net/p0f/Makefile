# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=		p0f
PORTVERSION=		1.8
CATEGORIES=		net
MASTER_SITES=		http://lcamtuf.hack.pl/
DISTNAME=		${PORTNAME}
EXTRACT_SUFX=		.tgz

MAINTAINER=		trevor@FreeBSD.org

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s=/etc=${PREFIX}/etc=g" \
		${WRKSRC}/README \
		${WRKSRC}/p0f.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/p0f
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p0f
.endif

.include <bsd.port.mk>
