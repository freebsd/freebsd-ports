# New ports collection makefile for:    speedtouch
# Date created:         August 30 2001
# Whom:                 Brian Somers <brian@freebsd-services.com>
#
# $FreeBSD$
#

PORTNAME=		pppoa
PORTVERSION=		1.1b
PORTEPOCH=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.xsproject.org/speedtouch/files/ \
			http://www.alcatel.com/consumer/dsl/ \
    			http://benoit.papillault.free.fr/speedtouch/
MASTER_SITE_SUBDIR=	speedtouch
DISTFILES=		${SPEEDTOUCH}.tar.gz ${ALCATELDRIVER}

MAINTAINER=		brian@FreeBSD.org

HAS_CONFIGURE=		yes
SPEEDTOUCH=		speedtouch-1.1b
ALCATELDRIVER=		speedmgmt.tar.gz
NO_CDROM=		"http://www.alcatel.com/consumer/dsl/disclaimer_lx.htm"
NO_PACKAGE=		"http://www.alcatel.com/consumer/dsl/disclaimer_lx.htm"
RESTRICTED_FILES=	${ALCATELDRIVER}

WRKSRC=			${WRKDIR}/${SPEEDTOUCH}

MAN1=			modem_run.1 pppoa2.1 pppoa3.1

post-install:
	${INSTALL} -m 0755 -o root -g wheel -d ${LOCALBASE}/libdata
	${INSTALL_DATA} ${WRKSRC}/../mgmt/mgmt.o ${LOCALBASE}/libdata
	${INSTALL_DATA} ${FILESDIR}/quick-install \
	    ${LOCALBASE}/share/doc/speedtouch/.
	@${CAT} ${LOCALBASE}/share/doc/speedtouch/quick-install

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${ALCATELDRIVER})
IGNORE=	You must manually fetch the Alcatel driver distribution (${DISTDIR}/${ALCATELDRIVER}) via http://www.speedtouchdsl.com/dvrreg_lx.htm (select binary release 1.3.3), place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.post.mk>
