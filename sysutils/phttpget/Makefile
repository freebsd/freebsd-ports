# Created by: Chris Hutchinson (portmaster@bsdforge.com)
# $FreeBSD$

PORTNAME=	phttpget
PORTVERSION=	0.2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.daemonology.net/phttpget/ \
		http://bsdforge.com/projects/source/sysutils/phttpget/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Pipelined HTTP GET utility

LICENSE=	BSD3CLAUSE

PLIST_FILES=	bin/phttpget

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/phttpget ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
