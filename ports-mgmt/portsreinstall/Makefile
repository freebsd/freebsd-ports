# New ports collection makefile for:	portsreinstall
# Date created:		2011-12-25
# Whom:			Mamoru Sakaue / MwGhennndo
#
# $FreeBSD$
#

PORTNAME=	portsreinstall
PORTVERSION=	0.9.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	SFJP/${PORTNAME}/50628/
MASTER_SITES+=	http://www.mwghennndo.com/softwares/${PORTNAME}/

MAINTAINER=	sakaue.mamoru@samurai.mwghennn.net
COMMENT=	Ports upgrading utility for massive forced reinstalltion

LICENSE=	BSD

RUN_DEPENDS=	${LOCALBASE}/sbin/pkgdb:${PORTSDIR}/ports-mgmt/portupgrade

MAN8=	${PORTNAME}.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
