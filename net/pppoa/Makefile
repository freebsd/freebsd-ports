# New ports collection makefile for:    speedtouch
# Date created:         August 30 2001
# Whom:                 Brian Somers <brian@freebsd-services.com>
#
# $FreeBSD$
#

PORTNAME=	pppoa
PORTVERSION=	20010815
CATEGORIES=	net
MASTER_SITES=	http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/ \
    		http://benoit.papillault.free.fr/speedtouch/
DISTFILES=	${SPEEDTOUCH}.tar.gz speedmgmt.tar.gz

MAINTAINER=	brian@Awfulhak.org

HAS_CONFIGURE=		yes
SPEEDTOUCH=		speedtouch-15082001
NO_CDROM=		"http://www.alcatel.com/consumer/dsl/disclaimer_lx.htm"
RESTRICTED_FILES=	speedmgmt.tar.gz

WRKSRC=			${WRKDIR}/${SPEEDTOUCH}

post-install:
	if [ ! -d ${PREFIX}/libdata ]; then			\
		${MKDIR} ${PREFIX}/libdata;			\
		${CHMOD} 775 ${PREFIX}/libdata;			\
		${CHOWN} root:wheel ${PREFIX}/arpwatch;		\
	fi
	${INSTALL_DATA} ${WRKSRC}/../mgmt/mgmt.o ${PREFIX}/libdata/.

.include <bsd.port.mk>
