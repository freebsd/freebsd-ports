# New ports collection Makefile for:	cvsupit
# Date created:		8 May 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	cvsupit
PORTVERSION=	3.1
CATEGORIES=	net
DISTFILES=	#empty

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	CVSup installation and setup front-end package (16.1 / GUI V3)

BROKEN=		"Does not build"

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE= 'Must configure cvsup server information'
.endif

RUN_DEPENDS=	cvsup:${PORTSDIR}/net/cvsup

.if (BATCH)
NO_INSTALL=	yes
.endif
NO_BUILD=	yes

do-install:
.if !make(package)
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.if defined(NO_INSTALL)
generate-plist:
	${DO_NADA}
process-plist:
	${DO_NADA}
.endif # defined(NO_INSTALL)


.include <bsd.port.mk>
