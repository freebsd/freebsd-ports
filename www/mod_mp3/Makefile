# New ports collection makefile for:	mod_mp3
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_mp3
PORTVERSION=	0.35
CATEGORIES=	www audio
MASTER_SITES=	http://software.tangent.org/download/ \
		ftp://ftp.tangent.org/pub/apache/ \
		http://www.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

HAS_CONFIGURE=	yes
MAKE_ARGS+=	APXS="${APXS}"

APXS?=		${LOCALBASE}/sbin/apxs
DOCS=		ChangeLog README TODO faq.html

do-install:
	${APXS} -i -A -n mp3 ${WRKSRC}/src/mod_mp3.so
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/mod_mp3
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mod_mp3/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
