# Created by: Tomaž Muraus <kami@k5-storitve.net>
# $FreeBSD$

PORTNAME=	gogoc
PORTVERSION=	1.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://gogo6.com/downloads/
DISTNAME=	gogoc-1_2-RELEASE

MAINTAINER=	kami@k5-storitve.net
COMMENT=	GogoCLIENT, connect to Freenet6 tunnel

USE_GMAKE=	yes
USE_RC_SUBR=	gogoc
USE_OPENSSL=	yes

MAKE_JOBS_UNSAFE=	yes

MAN5=		gogoc.conf.5
MAN8=		gogoc.8

PORTDOCS=	README CLIENT-LICENSE.TXT GUI-LICENSE.TXT

SUB_FILES=	gogoc
SUB_LIST=	LOCALBASE=${LOCALBASE}

NO_STAGE=	yes
do-install:
	cd ${WRKSRC}/gogoc-tsp/ && \
	    ${GMAKE} platform=freebsd installdir=${PREFIX} install
	${RM} ${PREFIX}/bin/gogoc.conf*
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gogoc-tsp/bin/gogoc.conf.sample ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

	@if [ ! -f ${PREFIX}/etc/gogoc.conf ]; then \
		${TOUCH} ${PREFIX}/etc/gogoc.conf ; \
	fi

.include <bsd.port.mk>
