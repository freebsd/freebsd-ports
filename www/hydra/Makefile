# ex:ts=8
# Ports collection makefile for:	hydra
# Date created:			Apr 2, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	0.1.8
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/ \
		ftp://ftp.hellug.gr/pub/software/hydra/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high performance multi-threaded web server

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

USE_RC_SUBR=	hydra.sh

NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

LOGDIR?=	/var/log/hydra

SUB_FILES=	pkg-deinstall
PLIST_SUB=	LOGDIR=${LOGDIR}
SUB_LIST=	LOGDIR=${LOGDIR}

post-patch:
	@${REINPLACE_CMD} -e "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure
.for f in src/defines.h examples/hydra.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
	                  -e "s,%%LOGDIR%%,${LOGDIR},g" \
	                  -e "s,%%WWWOWN%%,${WWWOWN},g" \
	                  -e "s,%%WWWGRP%%,${WWWGRP},g" \
	                  ${WRKSRC}/${f}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/etc/hydra
.for f in hydra.conf mime.types
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${PREFIX}/etc/hydra/${f}-dist
	[ -f ${PREFIX}/etc/hydra/${f} ] || \
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${PREFIX}/etc/hydra/
.endfor
	[ -d ${LOGDIR} ] || \
		( ${MKDIR} ${LOGDIR} && ${CHOWN} ${WWWOWN}:${WWWGRP} ${LOGDIR} )

.include <bsd.port.mk>
