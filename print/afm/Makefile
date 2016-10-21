# Created by: ljo
# $FreeBSD$

PORTNAME=	afm
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/source/
DISTNAME=	afm
EXTRACT_SUFX=	-tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adobe Font Metrics

NO_BUILD=	yes
pre-patch:
	@${RM} -r ${WRKSRC}/RCS

.include <bsd.port.mk>
