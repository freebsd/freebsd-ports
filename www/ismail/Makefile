# New ports collection makefile for:	ismail
# Date created:			18 June 2004
# Whom:				Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	ismail
PORTVERSION=	2.0.p4
CATEGORIES=	www mail
MASTER_SITES=	ftp://ftp.verbotenplanet.net/ISMail/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	kelley@insidesystems.net
COMMENT=	PHP-based webmail client

USE_BZIP2=	yes
USE_REINPLACE=	yes
ISMAILDIR?=	www/data/ismail
INSTALLDIR=	${PREFIX}/${ISMAILDIR}

WRKSRC=		${WRKDIR}/ISMail

PLIST_SUB=	ISMAILDIR=${ISMAILDIR}/ \
		INSTALLDIR=${INSTALLDIR}/

NO_BUILD=	yes
USE_PHP=	yes

.include <bsd.port.pre.mk>

PORTDOC_FILES= docs.html
PORT_EXAMPLES= mysql4.schema pgsql.schema

LIB_DEPENDS+=	c-client4.8:${PORTSDIR}/mail/cclient

SED_SCRIPT=	-e 's,%%INSTALL_DATA%%,${INSTALL_DATA},g' \
		-e 's,%%MKDIR%%,${MKDIR},g' \
		-e 's,%%WRKSRC%%,${WRKSRC},g' \
		-e 's,%%ISMAILDIR%%,${ISMAILDIR},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%INSTALLDIR%%,${INSTALLDIR},g'

pre-install:
	@${ECHO_MSG} "Inside Systems Mail will be installed to "
	@${ECHO_MSG} "${INSTALLDIR}."
	@${ECHO_MSG} "To change it, set the following:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "PREFIX = ${PREFIX}"
	@${ECHO_MSG} "ISMAILDIR = ${ISMAILDIR}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Inside Systems Mail requires that mod_php4 be build with"
	@${ECHO_MSG} "IMAP support. To enable IMAP support, you must set"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_IMAP=yes"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "One of the following mod_php4 extensions are required to"
	@${ECHO_MSG} "use the provided dastores:"
	@${ECHO_MSG} "
	@${ECHO_MSG} "  WITH_DOMXML=yes"
	@${ECHO_MSG} "  WITH_MYSQL=yes"
	@${ECHO_MSG} "  WITH_POSTGRESQL=yes"
	@${ECHO_MSG} "
	@${ECHO_MSG} "Hit Ctrl-C now to cancel the installation"
	@sleep 7
	@${SED} ${SED_SCRIPT} ${FILESDIR}/install.sh > ${WRKDIR}/install.sh
	@${SED} ${SED_SCRIPT} pkg-message > ${WRKDIR}/pkg-message

do-install:
	${SH} ${WRKDIR}/install.sh
	${CHMOD} -R 644 ${INSTALLDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${PORT_EXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${example} ${EXAMPLESDIR}
.endfor
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
