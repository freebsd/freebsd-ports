# New ports collection makefile for:	freedialog
# Date created:		30 October 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	freedialog
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.wam.umd.edu/pub/howardjp/software/dialog/ \
		http://www.wam.umd.edu/~howardjp/software/dialog/ \
		ftp://dragon.ham.muohio.edu/pub/howardjp/software/dialog/
DISTNAME=	dialog-${PORTVERSION}

MAINTAINER=	howardjp@wam.umd.edu

BUILD_DEPENDS=	${PREFIX}/lib/libiberty.so:${PORTSDIR}/devel/freelibiberty

MAN1=	dialog.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

.include <bsd.port.mk>
