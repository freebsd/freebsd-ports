# New ports collection makefile for:	mod_mp3
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_mp3
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	www audio
MASTER_SITES=	http://download.tangent.org/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module to allow MP3 streaming

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
HAS_CONFIGURE=	yes
MAKE_ARGS+=	APXS="${APXS}"
USE_PERL5=	yes

PORTDOCS=		ChangeLog README TODO faq.html CONTRIBUTORS

.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
.endif

do-install:
	${APXS} -i -A -n mp3 ${WRKSRC}/src/mod_mp3.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
