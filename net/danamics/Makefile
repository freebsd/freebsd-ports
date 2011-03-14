# New ports collection makefile for:	danamics
# Date created:		18 March 2003
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	danamics
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	ftp://ftp.cs.uct.ac.za/pub/FreeBSD/distfiles-local/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Petri Net editor for correctness and performance analysis

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/DaNAMiCS
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	DaNAMiCS DaNAMiCS.jar INSTALL dnamaca.opt

SUB_FILES=	danamics.sh
PLIST_FILES=	bin/danamics

.include <bsd.port.pre.mk>

post-install:
	@cd ${WRKSRC}; ${FIND} -s ${DATAFILES} -type f \
	  | ${SED} -e 's|^|${DATADIR:S,^${PREFIX}/,,}/|' >>${TMPPLIST}
	@cd ${WRKSRC};  ${FIND} -s -d ${DATAFILES} -type d \
	  | ${SED} -e 's|^|@dirrm ${DATADIR:S,^${PREFIX}/,,}/|' >>${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >>${TMPPLIST}

do-install:
	cd ${WRKSRC} \
	  && ${FIND} -s ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} -s ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/danamics.sh ${PREFIX}/bin/danamics

.include <bsd.port.post.mk>
