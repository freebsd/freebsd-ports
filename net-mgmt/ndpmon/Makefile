# New ports collection makefile for:	ndpmon
# Date created:				2006-12-17
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	ndpmon
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	On-link icmpv6 message monitoring and reporting daemon

USE_GNOME=	libxml2
USE_PERL5_RUN=	yes
USE_RC_SUBR=	ndpmonitor
WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE=FreeBSD

MAN8=		ndpmon.8
PORTDOCS=	INSTALL README

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/ndpmon.c \
		${WRKSRC}/ndpmon.8 \
		${WRKSRC}/config_ndpmon.xml \
		${WRKSRC}/neighbor_list.xml \
		${WRKSRC}/demopipeprogram.pl

do-install:
	${INSTALL_MAN} ${WRKSRC}/ndpmon.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ndpmon ${PREFIX}/sbin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd \
		${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demopipeprogram.pl \
		${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config_ndpmon.xml ${PREFIX}/etc/config_ndpmon.xml-dist
	${MKDIR} ${PREFIX}/var
	${INSTALL_DATA} ${WRKSRC}/neighbor_list.xml ${PREFIX}/var/ndpmon_neighbor_list.xml

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
