# New ports collection makefile for:    speedtouch
# Date created:         August 30 2001
# Whom:                 Brian Somers <brian@freebsd-services.com>
#
# $FreeBSD$
#

PORTNAME=		pppoa
PORTVERSION=		1.2
PORTEPOCH=		2
CATEGORIES=		net
MASTER_SITES=		http://download.ethomson.com/download/:mngt \
			${MASTER_SITE_SOURCEFORGE:S/$/:src/}
MASTER_SITE_SUBDIR=	speedtouch/:src
DISTFILES=		${SPEEDTOUCH}.tar.bz2:src ${ALCATELDRIVER}:mngt
EXTRACT_ONLY=		${SPEEDTOUCH}.tar.bz2

MAINTAINER=		tom@FreeBSD.org
COMMENT=		Run PPP over Alcatel's USB Speedtouch device

HAS_CONFIGURE=		yes
USE_REINPLACE=		yes
SPEEDTOUCH=		speedtouch-1.2
ALCATELDRIVER=		speedmgmt.tar.gz
RESTRICTED=		"http://www.speedtouchdsl.com/disclaimer_lx.htm"
RESTRICTED_FILES=	${ALCATELDRIVER}

WRKSRC=			${WRKDIR}/${SPEEDTOUCH}

MAN1=			modem_run.1 pppoa2.1 pppoa3.1
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
BROKEN=			"Configure fails on FreeBSD >= 6.x"
.endif

post-extract:
	@${TAR} -zxf ${DISTDIR}/${ALCATELDRIVER} -C ${WRKSRC}
	@${REINPLACE_CMD} s/-lkse/${PTHREAD_LIBS}/g ${WRKSRC}/configure

post-install:
	${INSTALL} -m 0755 -o root -g wheel -d ${LOCALBASE}/libdata
	${INSTALL_DATA} ${WRKSRC}/mgmt/mgmt.o ${LOCALBASE}/libdata
	${INSTALL_DATA} ${FILESDIR}/quick-install \
	    ${LOCALBASE}/share/doc/speedtouch/.
	@${CAT} ${LOCALBASE}/share/doc/speedtouch/quick-install

.include <bsd.port.post.mk>
