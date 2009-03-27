# New ports collection makefile for:	cyrus2courier
# Date created:				21 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	cyrus2courier
DISTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.madness.at/~mad/projects/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A Cyrus-Imap to Maildir++ conversion utility

MAKE_JOBS_SAFE=	yes

ALL_TARGET=	build

PLIST_FILES=	bin/cyrus2courier

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS*/d; /^LDFLAGS*/d; /^CC*/d' \
		${WRKSRC}/src/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
