# New ports collection makefile for:	mod_mp3
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_mp3
PORTVERSION=	0.40
CATEGORIES=	www audio
MASTER_SITES=	http://software.tangent.org/download/ \
		ftp://ftp.tangent.org/pub/apache/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to allow MP3 streaming

USE_APACHE=	yes
HAS_CONFIGURE=	yes
MAKE_ARGS+=	APXS="${APXS}"
USE_PERL5=	yes

DOCS=		ChangeLog README TODO faq.html CONTRIBUTORS

.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
.endif

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
