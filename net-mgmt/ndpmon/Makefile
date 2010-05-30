# New ports collection makefile for:	ndpmon
# Date created:				2006-12-17
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	ndpmon
PORTVERSION=	1.4.0
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-1.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	On-link icmpv6 message monitoring and reporting daemon

USE_GNOME=	libxml2
USE_PERL5_RUN=	yes
USE_RC_SUBR=	ndpmonitor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OSTYPE=FreeBSD
CONFIGURE_ARGS=	--with-var-datadir=${PREFIX}/var --with-confdir=${PREFIX}/etc

MAN8=		ndpmon.8
PORTDOCS=	INSTALL README

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/ndpmon.8 \
		${WRKSRC}/create_html_table.py \
		${WRKSRC}/demopipeprogram.pl.sample
	(cd ${WRKSRC}; ${MAKE} clean)

do-install:
	${INSTALL_MAN} ${WRKSRC}/ndpmon.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ndpmon ${PREFIX}/sbin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd \
		${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demopipeprogram.pl.sample \
		${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/create_html_table.py \
		${DATADIR}
	${MKDIR} ${PREFIX}/etc/ndpmon
	${INSTALL_DATA} ${WRKSRC}/config_ndpmon.xml ${PREFIX}/etc/ndpmon/config_ndpmon.xml-dist
	${MKDIR} ${PREFIX}/var/ndpmon
	${INSTALL_DATA} ${WRKSRC}/neighbor_list.xml ${PREFIX}/var/ndpmon/neighbor_list.xml

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
