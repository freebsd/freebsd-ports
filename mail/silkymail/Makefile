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
MASTER_SITES=	http://alkoholix.tallence.de/FreeBSD/ports/distfiles-local/silkymail/%SUBDIR%/ \
		ftp://ftp.cyrusoft.com/pub/SilkyMail/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:S/./_/g}
DISTNAME=       ${PORTNAME}
EXTRACT_SUFX=   .tgz

MAINTAINER=	voisine@yahoo.com
COMMENT=	A webmail system which accesses mail over IMAP

BROKEN=		doesn't fetch

USE_PHP=	dba imap
WANT_PHP_MOD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
NO_PACKAGE=	requires GDBM support in databases/php4-dba, which is off by default

SILKYMAILDIR=	${LOCALBASE}/www/${PORTNAME}

do-install:
	@${MKDIR} -p ${SILKYMAILDIR}
	@${CP} -r ${WRKSRC} ${SILKYMAILDIR}
	@${CHOWN} www:www ${SILKYMAILDIR}/silkymail/imp/data

pre-install:
	@if ! /usr/bin/ldd -a ${LOCALBASE}/lib/php/20020429/dba.so | ${GREP} -q -e "libgdbm.so"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "databases/php4-dba needs to be built with GDBM support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%SILKYMAILDIR%%:${SILKYMAILDIR}:g;s:%%LOCALBASE%%:${LOCALBASE}:g;"
	@${ECHO_MSG}

.include <bsd.port.mk>
