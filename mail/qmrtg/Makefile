# New ports collection makefile for:   qmrtg
# Date created:        12 Jun 2004
# Whom:                Mij
#
# $FreeBSD$
#

PORTNAME=	qmrtg
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	mail net-mgmt
MASTER_SITES=	http://dev.publicshout.org/qmrtg/download/

MAINTAINER=	mij@bitchx.it
COMMENT=	A simple tool for monitoring and graphing qmail activity through MRTG

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${BUILD_DEPENDS}
.if !defined(WITHOUT_MRTG)
RUN_DEPENDS+=	mrtg:${PORTSDIR}/net-mgmt/mrtg
.endif

USE_BZIP2=	yes

MAN8=		qfilt.8 qmrtg-concurrency.8 qmrtg-dnsbl.8 \
		qmrtg-queue.8 qmrtg-regex.8 qmrtg-throughput.8 \
		qmrtg.8 qtaif.8
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes

# where is qmrtg' database directory
QMRTG_DBDIR:=	/var/db/${PORTNAME}

# variables to be "exported" to plist
PLIST_SUB=	QMRTG_DBDIR=${QMRTG_DBDIR}

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
# interactive --> ask user for options
IS_INTERACTIVE=		yes
.if !defined(NOPORTDOCS)
# install extra doc by default
OPTIONS=	\
	DOCS		"Install LICENSE, FAQs etc (shared doc)"	On \
	HTMLTEMPLATES	"Install QMRTG HTML templates"			On
.else		# defined(NOPORTDOCS)
# avoid to offer to install doc
OPTIONS=	\
	HTMLTEMPLATES	"Install QMRTG HTML templates"			On
.endif		# !defined(NOPORTDOCS)
.else		# defined(PACKAGE_BUILDING) || defined(BATCH)
# building batch
# setting defaults
WITH_HTMLTEMPLATES=	yes
.if !defined(NOPORTDOCS)
# also install doc by default
WITH_DOCS=	yes
.endif		# !defined(NOPORTDOCS)
.endif		# !defined(PACKAGE_BUILDING)

.include <bsd.port.pre.mk>

pre-extract:
	@${ECHO_MSG} "   --->   Qmrtg can be installed without MRTG by defining WITHOUT_MRTG"

post-install:
# possibly installing docs
.if defined(WITH_DOCS) && !defined(NOPORTDOCS)
	@${ECHO_MSG} "   --->   Installing QMRTG extra docs as requested [ ${DOCSDIR} ]"
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
.endif
# possibly installing HTML templates
.if defined(WITH_HTMLTEMPLATES)
	@${ECHO_MSG} "   --->   Installing examples as requested [ ${EXAMPLESDIR} ]"
	${MKDIR} ${DATADIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DATADIR}/html
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mrtg.cfg ${EXAMPLESDIR}
.endif
# creating db directory
	@${ECHO_MSG} "   --->   Creating QMRTG db directory [ ${QMRTG_DBDIR} ]"
	${MKDIR} ${QMRTG_DBDIR}
# installing configuration example
	@${ECHO_MSG} "   --->   Installing configuration example [ ${PREFIX}/etc/qmrtg.conf.dist ]"
	${MKDIR} ${PREFIX}/etc
	${CP} ${WRKSRC}/examples/qmrtg.conf.sample ${PREFIX}/etc/qmrtg.conf.dist
# displaying the port install msg
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
