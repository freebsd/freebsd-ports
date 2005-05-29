# New ports collection makefile for:	mod_auth_external
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_external
PORTVERSION=	2.1.19
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Enables the use of external mechanisms for user authentication

USE_APACHE=	yes
DOCS=		AUTHENTICATORS CHANGES INSTALL README TODO

CONFLICTS=	apache-contrib-1.*

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_auth_external.c

do-install:
	${APXS} -i -A -n auth_external ${WRKSRC}/mod_auth_external.so
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}/examples
	cd ${WRKSRC} && ${TAR} -chf - mysql radius sybase test \
		| ${TAR} -xf - -C ${DOCSDIR}/examples
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
