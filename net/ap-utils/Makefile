# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.0.3
CATEGORIES=	net
MASTER_SITES=	http://ap-utils.polesye.net/files/

MAINTAINER=	jerry@thehutt.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/FAQ \
		${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/Documentation/README.* \
		${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/Documentation/THANKS \
		${PREFIX}/share/doc/${PORTNAME}
	@${MKDIR} ${DOCSDIR}/mib
	${INSTALL_DATA} ${WRKSRC}/Documentation/mib/*.mib \
		${PREFIX}/share/doc/${PORTNAME}/mib
	${INSTALL_DATA} ${WRKSRC}/Documentation/mib/README \
		${PREFIX}/share/doc/${PORTNAME}/mib
.endif

.include <bsd.port.mk>
