# New ports collection makefile for:	tuxcards
# Date created:				08 Jan 2002
# Whom:			Tilman linneweh <freebsdports@arved.de>
#
# $FreeBSD$
#

PORTNAME=	tuxcards
PORTVERSION=	0.8
CATEGORIES=	misc kde
MASTER_SITES=	http://tuxcards.de/src/ \
		http://www.arved.de/bsd/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsdports@arved.de

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_QT_VER=	2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

pre-patch:
	@${PERL} -pi -e 's|\$$\(prefix\)/doc|\$$\(prefix\)/share/doc|' \
		${WRKSRC}/tuxcards/docs/en/Makefile.in
	@${PERL} -pi -e 's|-O2||' ${WRKSRC}/configure
.ifdef(NOPORTDOCS)
	@${PERL} -pi -e 's|install-data-am\: install-data-local||' \
		${WRKSRC}/tuxcards/docs/en/Makefile.in
.endif #NOPORTDOCS

.include <bsd.port.mk>
