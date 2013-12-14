# Created by: Mamoru Sakaue / MwGhennndo
# $FreeBSD$

PORTNAME=	portsreinstall
PORTVERSION=	3.0.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	SFJP/${PORTNAME}/60071/ \
		http://www.mwghennndo.com/software/${PORTNAME}/

MAINTAINER=	sakaue.mamoru@samurai.mwghennn.net
COMMENT=	Ports upgrading utility for massive forced reinstall

LICENSE=	BSD

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

post-install:
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} "This software invokes some installed files of portupgrade(1)"
	@${ECHO_MSG} "if it is installed for parsing pkgtools.conf(5) although dependency"
	@${ECHO_MSG} "to it is intendedly refrained. If you fail to parse pkgtools.conf(5),"
	@${ECHO_MSG} "try to upgrade this port first."
	@${ECHO_MSG} "====================================================================="

.include <bsd.port.mk>
