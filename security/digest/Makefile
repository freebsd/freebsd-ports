# New ports collection makefile for:	digest
# Date created:				2001-03-09
# Whom:					trevor
#
# $NetBSD: Makefile,v 1.37 2003/07/17 22:52:13 grant Exp $
# $FreeBSD$
#

PORTNAME=	digest
PORTVERSION=	${VERSION}
CATEGORIES=	security sysutils
MASTER_SITES=	#
DISTFILES=

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Message digest wrapper utility

CONFLICTS=	nss-[0-9]* emboss-[0-9]*

GNU_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

MAN1=		digest.1

PLIST_FILES=	bin/digest

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

VERSION!=	${AWK} -F "'" '/^PACKAGE_VERSION=/ {print $$2}' \
		${FILESDIR}/configure

post-extract:
	@${CP} -Rp ${FILESDIR}/* ${WRKSRC}
	@${CHMOD} +x ${WRKSRC}/configure

test: build
	@${ECHO} "No news is good news"
	@cd ${WRKSRC} && ${SETENV} DIGESTDIR=${WRKSRC} ${SH} ./regress.sh
	@${ECHO} "All tests completed"

.include <bsd.port.post.mk>
