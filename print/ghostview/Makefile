# New ports collection makefile for:	ghostview
# Date created:		21 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	ghostview
PORTVERSION=	1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ghostview

MAINTAINER=	ports@FreeBSD.org

FORBIDDEN=	"Security vulnerability, see bugtraq id 5808"

USE_IMAKE=	yes
MAN1=		ghostview.1

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
