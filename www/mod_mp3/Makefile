# New ports collection makefile for:	mod_auth_pam
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_mp3
PORTVERSION=	0.9
CATEGORIES=	www audio
MASTER_SITES=	http://www.tangent.org/mod_mp3/ \
		ftp://ftp.tangent.org/pub/apache/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

APXS?=		${LOCALBASE}/sbin/apxs
DOCS=		ChangeLog README TODO faq.html

do-build:
	@cd ${WRKSRC} && ${APXS} -c mod_mp3.c

do-install:
	${APXS} -i -A -n mp3 ${WRKSRC}/mod_mp3.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_mp3
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_mp3/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
