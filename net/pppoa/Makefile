# New ports collection makefile for:    speedtouch
# Date created:         August 30 2001
# Whom:                 Brian Somers <brian@freebsd-services.com>
#
# $FreeBSD$
#

PORTNAME=	pppoa
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://prdownloads.sourceforge.net/speedtouch/ \
		http://www.xsproject.org/speedtouch/files/ \
		http://www.alcatel.com/consumer/dsl/ \
    		http://benoit.papillault.free.fr/speedtouch/
DISTFILES=	${SPEEDTOUCH}.tar.gz speedmgmt.tar.gz

MAINTAINER=	brian@Awfulhak.org

HAS_CONFIGURE=		yes
SPEEDTOUCH=		speedtouch-1_0
NO_CDROM=		"http://www.alcatel.com/consumer/dsl/disclaimer_lx.htm"
NO_PACKAGE=		"http://www.alcatel.com/consumer/dsl/disclaimer_lx.htm"
RESTRICTED_FILES=	speedmgmt.tar.gz

WRKSRC=			${WRKDIR}/${SPEEDTOUCH}

MAN1=			modem_run.1 pppoa2.1 pppoa3.1

post-install:
	if [ ! -d ${PREFIX}/libdata ]; then			\
		${MKDIR} ${PREFIX}/libdata;			\
		${CHMOD} 775 ${PREFIX}/libdata;			\
		${CHOWN} root:wheel ${PREFIX}/libdata;		\
	fi
	${INSTALL_DATA} ${WRKSRC}/../mgmt/mgmt.o ${PREFIX}/libdata/.
	${INSTALL_DATA} ${FILESDIR}/quick-install ${PREFIX}/share/speedtouch/.
	${CAT} ${PREFIX}/share/speedtouch/quick-install

.include <bsd.port.mk>
