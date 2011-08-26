# New ports collection makefile for:	rlytest
# Date created:		16 January 1999
# Whom:			Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	rlytest
PORTVERSION=	1.22
CATEGORIES=	mail security
MASTER_SITES=	http://www.unicom.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test remote system for unsecured mail relay

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${PORTNAME}

NO_WRKSUBDIR=	yes

USE_PERL5_RUN=	yes

MAN1=		rlytest.1
PLIST_FILES=	bin/rlytest

post-patch:
	@${REINPLACE_CMD} -e 's|^#!.*|#!${PERL}|' ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && pod2man ${PORTNAME} > ${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
