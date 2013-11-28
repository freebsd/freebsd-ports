# Created by: Mamoru Sakaue / MwGhennndo
# $FreeBSD$

PORTNAME=	portsreinstall
PORTVERSION=	3.0.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	SFJP/${PORTNAME}/59894/ \
		http://www.mwghennndo.com/software/${PORTNAME}/

MAINTAINER=	sakaue.mamoru@samurai.mwghennn.net
COMMENT=	Ports upgrading utility for massive forced reinstall

LICENSE=	BSD

MAN8=		${PORTNAME}.8
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

post-install:
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} "This software invokes some installed files of portupgrade(1)"
	@${ECHO_MSG} "if it is installed for parsing pkgtools.conf(5) although dependency"
	@${ECHO_MSG} "to it is intendedly refrained. If you fail to parse pkgtools.conf(5),"
	@${ECHO_MSG} "try to upgrade this port first."
	@${ECHO_MSG} "====================================================================="

.include <bsd.port.mk>
