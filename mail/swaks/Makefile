# New ports collection makefile for:	swaks
# Date created:				29 Sep 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=	swaks
PORTVERSION=	20040404.1
CATEGORIES=	mail
MASTER_SITES=	http://jetmore.org/john/code/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Swiss Army Knife SMTP transaction tester

PLIST_FILES=	bin/${PORTNAME}

USE_PERL5_RUN=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${SED} -e '1s|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${DISTNAME} > ${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${DESTDIR}${PREFIX}/bin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
