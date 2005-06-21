# New ports collection makefile for:   vexim
# Date created:        6 June 2005
# Whom:                John Oxley <john@yoafrica.com>
#
# $FreeBSD$

PORTNAME=	vexim
PORTVERSION=	2.0.1
CATEGORIES=	mail www
MASTER_SITES=	http://silverwraith.com/vexim/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	john@yoafrica.com
COMMENT=	A web interface for managing virtual domains for exim

VEXIMDIR=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/vexim2

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
NO_BUILD=	yes
USE_MYSQL=	yes
USE_APACHE=	yes
USE_PHP=	yes

post-patch:
	${FIND} ${WRKSRC} -name CVS -prune -exec ${RM} -r {} \;

do-install:
	@${ECHO} "Installing in ${VEXIMDIR}"
	${MKDIR} ${PREFIX}/${VEXIMDIR}
	cd ${WRKSRC}/vexim && ${FIND} . \
		-type d -exec ${MKDIR} ${PREFIX}/${VEXIMDIR}/{} \;  \
		-o -type f -exec ${INSTALL_DATA} {} ${PREFIX}/${VEXIMDIR}/{} \;
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/setup && ${FIND} . \
		-type d -exec ${MKDIR} ${DATADIR}/{} \; \
		-o -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} docs \
		-type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
		-o -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.for i in INSTALL LICENSE README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
