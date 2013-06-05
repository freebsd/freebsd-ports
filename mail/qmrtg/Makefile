# Created by: Mij
# $FreeBSD$

PORTNAME=	qmrtg
PORTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	mail net-mgmt
MASTER_SITES=	http://dev.publicshout.org/qmrtg/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple tool for monitoring and graphing qmail activity through MRTG

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		mrtg:${PORTSDIR}/net-mgmt/mrtg

DEPRECATED=	lacks an upstream source
EXPIRATION_DATE=	2013-08-01

.include <bsd.port.options.mk>

USE_BZIP2=	yes

MAN8=		qfilt.8 qmrtg-concurrency.8 qmrtg-dnsbl.8 \
		qmrtg-queue.8 qmrtg-regex.8 qmrtg-throughput.8 \
		qmrtg.8 qtaif.8
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes

QMRTG_DBDIR:=	/var/db/${PORTNAME}

PLIST_SUB=	QMRTG_DBDIR=${QMRTG_DBDIR}

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE=		yes
.endif		# !defined(PACKAGE_BUILDING)

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${DATADIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DATADIR}/html
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mrtg.cfg ${EXAMPLESDIR}
.endif

	${MKDIR} ${QMRTG_DBDIR}
	${MKDIR} ${PREFIX}/etc
	${CP} ${WRKSRC}/examples/qmrtg.conf.sample ${PREFIX}/etc/qmrtg.conf.dist
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
