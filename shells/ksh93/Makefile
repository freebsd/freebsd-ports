# New ports collection makefile for:   ksh93
# Date created:                2000-12-26
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	ksh93
PORTVERSION=	${VERSION:S/-//g}
PORTREVISION=	1
VERSION=	2001-10-31
CATEGORIES=	shells
MASTER_SITES=	http://www.research.att.com/~gsf/download/tgz/
DISTNAME=	${PORTNAME}-${VERSION}
DISTFILES=	INIT.${VERSION}.tgz ast-ksh.${VERSION}.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org

RESTRICTED=	"Source recipient must acknowledge license"

NO_WRKSUBDIR=	yes
MAKE_ARGS=	CC='${CC}' CCFLAGS='${CFLAGS}' SHELL='${SH}'
.if defined(WANT_STATIC)
MAKE_ARGS+=	LDFLAGS=-static
.endif

MAN1=		ksh93.1

do-build:
	@cd ${WRKSRC}; ./bin/package make ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arch/freebsd.${ARCH}/bin/ksh \
	    ${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${WRKSRC}/arch/freebsd.${ARCH}/man/man1/sh.1 \
	    ${PREFIX}/man/man1/ksh93.1

post-install:
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/ksh93 /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/ksh93) >/etc/shells
	@${RM} -f /etc/shells.bak

.include <bsd.port.mk>
