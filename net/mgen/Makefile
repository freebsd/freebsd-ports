# New ports collection makefile for:	rude
# Date created:		04/11/2004
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	mgen
PORTVERSION=	4.2b5
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/mgen/
EXTRACT_SUFX=	.tgz
DISTFILES=	src-${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	An IP network performance tests and measurements

IGNORE=		does not respect PTHREAD_LIBS

USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/mgen
PORTDOCS=	README.TXT VERSION.TXT mgen.html example.mgn

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/unix/Makefile.common \
		${WRKSRC}/protolib/unix/Makefile.common

do-build:
	cd ${WRKSRC}/unix && ${GMAKE} -f Makefile.freebsd ${PORTNAME}

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/unix/mgen ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
