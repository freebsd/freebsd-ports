# New ports collection makefile for:		lam
# Date created:					Aug 21 2001
# Whom:						bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	lam7
PORTVERSION=	7.0.5
CATEGORIES=	net parallel
MASTER_SITES=	http://www.lam-mpi.org/download/files/ \
		http://www.thinkingnerds.com/lam/download/files/
DISTNAME=	lam-${PORTVERSION}

MAINTAINER=	jan.lentfer@web.de
COMMENT=	Local Area Multicomputer MPI implementation

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-rsh=ssh

CONFLICTS=	lam-6.*

.include "files/manpages"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		"Broken pkg-plist on amd64 and sparc64"
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
