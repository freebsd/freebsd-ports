# Ports collection makefile for:  silkymail
# Date created:			  Mon Jan 27, 2003
# Whom:				  Aaron Voisine (voisine@yahoo.com)
#
# $FreeBSD$
#

PORTNAME=	silkymail
PORTVERSION=	1.1.10
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.cyrusoft.com/pub/SilkyMail/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:S/./_/g}
DISTNAME=       ${PORTNAME}
EXTRACT_SUFX=   .tgz

MAINTAINER=	voisine@yahoo.com
COMMENT=	A webmail system which accesses mail over IMAP

RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
NO_PACKAGE=	"Requires IMAP/IMAP_SSL enabled in www/mod_php4"

SILKYMAILDIR=	${LOCALBASE}/www/${PORTNAME}

do-install:
	@${MKDIR} -p ${SILKYMAILDIR}
	@${CP} -r ${WRKSRC} ${SILKYMAILDIR}
	@${CHOWN} www:www ${SILKYMAILDIR}/silkymail/imp/data

pre-install:
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "c-client4.8"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure mod_php4 with IMAP or IMAP-SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "gdbm.3"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure mod_php4 with GDBM support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%SILKYMAILDIR%%:${SILKYMAILDIR}:g;s:%%LOCALBASE%%:${LOCALBASE}:g;"
	@${ECHO_MSG}

.include <bsd.port.mk>
