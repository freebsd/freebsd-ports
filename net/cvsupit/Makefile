# New ports collection Makefile for:	cvsupit
# Date created:		8 May 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	cvsupit
PORTVERSION=	3.0
CATEGORIES=	net
DISTFILES=	#empty

MAINTAINER=	jkh@freebsd.org

BUILD_DEPENDS=	cvsup:${PORTSDIR}/net/cvsup-bin

.if (BATCH)
NO_INSTALL=	yes
.endif
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-extract:
	cd ${FILESDIR} ; \
		${CP} -p Makefile ${WRKDIR}

post-install:
.if !make(package)
	@${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
