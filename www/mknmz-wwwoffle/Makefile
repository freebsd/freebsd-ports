# New ports collection makefile for:   mknmz-wwwoffle
# Date created:        2 May 2004
# Whom:                Andrey Slusar <vasallia@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	mknmz-wwwoffle
PORTVERSION=	0.7.2
CATEGORIES=	www databases textproc
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	anray@inet.ua
COMMENT=	WWWOFFLE cache indexer for full-text search system Namazu

RUN_DEPENDS=	${LOCALBASE}/bin/wwwoffle:${PORTSDIR}/www/wwwoffle
BUILD_DEPENDS=	${LOCALBASE}/bin/mknmz:${PORTSDIR}/databases/namazu2

USE_PERL5=	yes
HAS_CONFIGURE=	yes

MAN1=		mknmz-wwwoffle.1
PORTDOCS=	AUTHORS COPYING INSTALL INSTALL.ja NEWS README README.ja THANKS

post-build:
.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
