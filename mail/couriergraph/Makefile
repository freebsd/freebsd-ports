# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	couriergraph
PORTVERSION=	20060202
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.arschkrebs.de/postfix/${PORTNAME}/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RRDtool frontend for Courier statistics

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

USES=		perl5
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DATADIR?=	/var/db/couriergraph
COURIERGRAPH_USER?=	${WWWOWN}
COURIERGRAPH_GROUP?=	${WWWGRP}

SUB_LIST=	COURIERGRAPH_USER=${COURIERGRAPH_USER} \
		COURIERGRAPH_GROUP=${COURIERGRAPH_GROUP}
STARTUP_FILE=	${PREFIX}/etc/rc.d/couriergraph.sh

SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may set the following options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "DATADIR=/var/db/couriergraph	Where do you put RRD databases?"
	@${ECHO_MSG} "COURIERGRAPH_USER=www		User to run couriergraph (default: ${WWWOWN})"
	@${ECHO_MSG} "COURIERGRAPH_GROUP=www		Group to run couriergraph (default: ${WWWGRP})"
	@${ECHO_MSG}

# To avoid conflict between default WRKSRC and RC_SUBR file being the same
post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," \
		${WRKSRC}/couriergraph.cgi ${WRKSRC}/couriergraph.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CHOWN} -R ${COURIERGRAPH_USER}:${COURIERGRAPH_GROUP} \
		${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/couriergraph.pl \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/couriergraph.cgi \
		${STAGEDIR}${PREFIX}/www/cgi-bin

.include <bsd.port.mk>
