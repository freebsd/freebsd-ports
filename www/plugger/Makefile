# New ports collection makefile for:	plugger
# Version required:	3.0
# Date created:		11 Februrary 1999
# Whom:			Jay Sachs <sachs@cs.williams.edu>
#
# $FreeBSD$
#

DISTNAME=	plugger-3.0
CATEGORIES=	www
MASTER_SITES=	http://www.hubbe.net/~hubbe/plugger/ \
		ftp://ftp.netscape.com/pub/sdk/plugin/unix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} unix-sdk-3.0b5.tar.Z

MAINTAINER=	sachs@cs.williams.edu

RUN_DEPENDS=	${LOCALBASE}/lib/netscape/plugins:${PORTSDIR}/www/netscape47-navigator

MAN7=		plugger.7
MANCOMPRESSED=	no

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} \
	  -e 's#/usr/local/#${PREFIX}/#' \
	  -e 's#/usr/X11/#${X11BASE}/#' \
	  -e 's#/etc/pluggerrc#${PREFIX}/etc/pluggerrc.sample#' \
	  -e 's# /etc/ # ${PREFIX}/etc/pluggerrc.sample #' \
	  ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:/usr/local:${PREFIX}:'

.include <bsd.port.mk>
