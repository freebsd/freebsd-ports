# New ports collection makefile for:	pxytest
# Date created:				Fri Jun 13 05:57:43 EDT 2003
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	pxytest
PORTVERSION=	1.36
CATEGORIES=	security
MASTER_SITES=	http://www.unicom.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test remote system for unsecured mail proxies

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${PORTNAME}

NO_WRKSUBDIR=	yes

USE_PERL5_RUN=	yes

MAN1=		pxytest.1
PLIST_FILES=	bin/pxytest

post-patch:
	@${REINPLACE_CMD} -e \
		's:^#!.*:#!${PERL}:' ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && pod2man ${PORTNAME} > ${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
