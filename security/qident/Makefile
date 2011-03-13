# New ports collection makefile for:	qident
# Date created:			30 August 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	qident
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.hairylemon.org/~ad/software/qident/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query a remote IDENT (RFC 1413) server

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	ident.0:${PORTSDIR}/security/libident

MANSECTS=	1
MAN1=		qident.1
MANCOMPRESSED=	maybe

# MAN page COMPression SUFFIX
.if !defined(NO_MANCOMPRESS)
MANCOMPSUFFIX=	.gz
.else
MANCOMPSUFFIX=
.endif

PLIST_FILES=	bin/qident

post-patch:
	@${REINPLACE_CMD} -e 's/getopt[.]h/unistd.h/g' ${WRKSRC}/*

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qident ${PREFIX}/bin/qident
.for __s in ${MANSECTS}
.for __m in ${MAN${__s}:S/$/${MANCOMPSUFFIX}/}
	@${INSTALL_MAN} ${WRKSRC}/${__m} ${PREFIX}/man/man${__s}/${__m}
.endfor
.endfor

.include <bsd.port.mk>
