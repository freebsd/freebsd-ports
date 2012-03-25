# New ports collection makefile for:	portsreinstall
# Date created:		2011-12-25
# Whom:			Mamoru Sakaue / MwGhennndo
#
# $FreeBSD$
#

PORTNAME=	portsreinstall
PORTVERSION=	1.0.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	SFJP/${PORTNAME}/55243/
MASTER_SITES+=	http://www.mwghennndo.com/softwares/${PORTNAME}/

MAINTAINER=	sakaue.mamoru@samurai.mwghennn.net
COMMENT=	Ports upgrading utility for massive forced reinstalltion

LICENSE=	BSD

MAN8=	${PORTNAME}.8
MANCOMPRESSED=	yes

post-install:
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} "This software invokes some installed files of portupgrade(1)"
	@${ECHO_MSG} "when parsing pkgtools.conf(5) although dependency to it is intendedly"
	@${ECHO_MSG} "refrained. If you fail to parse pkgtools.conf(5), try to upgrade"
	@${ECHO_MSG} "this port first."
	@${ECHO_MSG} "====================================================================="

.include <bsd.port.mk>
