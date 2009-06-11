# New ports collection makefile for:    speedtouch
# Date created:         August 30 2001
# Whom:                 Brian Somers <brian@freebsd-services.com>
#
# $FreeBSD$
#

PORTNAME=		pppoa
PORTVERSION=		1.3.1
PORTEPOCH=		2
CATEGORIES=		net
MASTER_SITES=		http://www.oracle-base.com/articles/misc/:mngt \
			${MASTER_SITE_SOURCEFORGE:S/$/:src/}
MASTER_SITE_SUBDIR=	speedtouch/:src
DISTFILES=		${SPEEDTOUCH}.tar.bz2:src ${ALCATELDRIVER}:mngt
EXTRACT_ONLY=		${SPEEDTOUCH}.tar.bz2

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Run PPP over Alcatel's USB Speedtouch device

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
SPEEDTOUCH=		speedtouch-${PORTVERSION}
ALCATELDRIVER=		speedmgmt.tar.gz
RESTRICTED=		http://www.speedtouchdsl.com/disclaimer_lx.htm
RESTRICTED_FILES=	${ALCATELDRIVER}

WRKSRC=			${WRKDIR}/${SPEEDTOUCH}

MAN8=			modem_run.8 pppoa2.8 pppoa3.8
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

post-extract:
	@${TAR} -zxf ${DISTDIR}/${ALCATELDRIVER} -C ${WRKSRC}
	@${REINPLACE_CMD} s/-lkse/${PTHREAD_LIBS}/g ${WRKSRC}/configure

post-patch:
	@${REINPLACE_CMD} 's/\@INSTALL_MAN\@/${INSTALL_MAN}/' \
		${WRKSRC}/doc-bsd/Makefile.in

post-install:
	${INSTALL} -m 0755 -o root -g wheel -d ${PREFIX}/libdata
	${INSTALL_DATA} ${WRKSRC}/mgmt/mgmt.o ${PREFIX}/libdata
	${INSTALL_DATA} ${FILESDIR}/quick-install \
	    ${PREFIX}/share/doc/speedtouch/.
	@${CAT} ${PREFIX}/share/doc/speedtouch/quick-install

.include <bsd.port.post.mk>
