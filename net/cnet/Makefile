# New ports collection makefile for:    cnet
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	cnet
PORTVERSION=	1.7.7
CATEGORIES=	net tk83
MASTER_SITES=	http://www.cs.uwa.edu.au/cnet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty
MAN1=		cnet.1

post-patch:
	@${PERL} -pi -e 's|8.2|8.3|g ; \
		 s|82|83|g' ${WRKSRC}/src/Makefile.freebsd
	@${PERL} -pi -e 's|%%CC%%|${CC}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cnet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/cnet.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/DOC/cnet.man ${PREFIX}/man/man1/cnet.1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cnetlib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/cnet
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES/* ${PREFIX}/share/examples/cnet
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/DOC/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
