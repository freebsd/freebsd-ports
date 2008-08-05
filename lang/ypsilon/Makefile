# New ports collection makefile for:	ypsilon
# Date created:		27 July 2008
# Whom:			Vitaly Magerya <vmagerya@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ypsilon
PORTVERSION=	0.9.6
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme implementation for real-time applications

USE_GMAKE=	yes
MAKE_ARGS=	PROG="${PORTNAME}" \
		DATADIR="${DATADIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		ypsilon.1

ONLY_FOR_ARCHS=	i386

post-patch:
	${RM} ${WRKSRC}/sitelib/*.orig

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "sitelib stdlib" ${DATADIR})
.ifndef (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example/*.scm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
