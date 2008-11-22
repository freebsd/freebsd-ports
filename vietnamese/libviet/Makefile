# ex:ts=8
# Ports collection makefile for:    libviet
# Date created:         Fri Feb 09, 2001
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	libviet
PORTVERSION=	20010210
PORTREVISION=	1
CATEGORIES=	vietnamese devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	VIQR<->VISCII conversion and VISCII ctype-like routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/lib
USE_BZIP2=	yes

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libvntype.a ${WRKSRC}/libviqr.a  \
		${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/viet
	@cd ${WRKSRC}/../include ; ${INSTALL_DATA} \
		charset.h charseta.h charsetv.h ctype.h portable.h vncompos.h vnkeys.h vntype.h  \
		${PREFIX}/include/viet
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} \
		&& ${CHMOD} a+rx ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/../README.lib ${DOCSDIR}
.endif

.include <bsd.port.mk>
