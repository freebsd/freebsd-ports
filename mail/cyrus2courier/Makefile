# New ports collection makefile for:	cyrus2courier
# Date created:				21 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	cyrus2courier
DISTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.madness.at/~mad/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A Cyrus-Imap to Maildir++ conversion utility

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes

ALL_TARGET=	build

PLIST_FILES=	bin/cyrus2courier

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS*/d; /^LDFLAGS*/d; /^CC*/d' \
		${WRKSRC}/src/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
