# New ports collection makefile for:	freedialog
# Version required:	0.3
# Date created:		30 October 1999
# Whom:			James Howard <howardj@wam.umd.edu>
#
# $FreeBSD$
#

DISTNAME=	dialog-0.3
PKGNAME=	freedialog-0.3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.wam.umd.edu/pub/howardjp/software/dialog/ \
		http://www.wam.umd.edu/~howardjp/software/dialog/ \
		ftp://dragon.ham.muohio.edu/pub/howardjp/software/dialog/

MAINTAINER=	howardjp@wam.umd.edu

BUILD_DEPENDS=	${PREFIX}/lib/libiberty.so:${PORTSDIR}/devel/freelibiberty

MAN1=	dialog.1

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

.include <bsd.port.mk>
