# New ports collection makefile for:	buddy
# Date created:		31 August 2004
# Whom:			Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	buddy
PORTVERSION=	2.4
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	buddy

MAINTAINER=	llwang@infor.org
COMMENT=	A Binary Decision Diagram library

USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

DOCS=		doc/bddnotes.ps doc/buddy.ps doc/tech.txt README AUTHORS

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
