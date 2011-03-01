# New ports collection makefile for:	exipick
# Date created:				29 Sep 2004
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	exipick
PORTVERSION=	20100323.0
CATEGORIES=	mail
MASTER_SITES=	http://jetmore.org/john/code/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Display messages from Exim queue based on a variety of criteria

PLIST_FILES=	bin/${PORTNAME}

USE_PERL5_RUN=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${SED} -e '1s|/usr/bin/perl|${PERL}|' \
		-e 's;\/local\/exim\/spool;\/var\/spool\/exim;g' \
		${WRKSRC}/${DISTNAME} > ${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
