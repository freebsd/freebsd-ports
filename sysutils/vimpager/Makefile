# New ports collection makefile for:	vimpager
# Date created:				10 December 2011
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vimpager
PORTVERSION=	1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${GH_DEVELOPER}/${GH_PORTNAME}/tarball/${DISTVERSION}/
DISTNAME=	${GH_DEVELOPER}-${GH_PORTNAME}-${DISTVERSION}-0-g${GH_VERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

# Github makes this very confusing
GH_PORTNAME=	${PORTNAME}
GH_DEVELOPER=	rkitover	#GH trees live under a username
GH_VERSION=	159ed2c8c7	#GH appends a commit hash to the filename
GH_SRCDIR=	4f3a5e9		#GH appends something else (??) to the extracted pathname
WRKSRC=		${WRKDIR}/${GH_DEVELOPER}-${GH_PORTNAME}-${GH_SRCDIR}
FETCH_ARGS=	-prR		#GH issues HTTP/302 errors for source tarballs

PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
