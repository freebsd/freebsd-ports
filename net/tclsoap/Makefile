# Created by: Sebastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	tclsoap
PORTVERSION=	1.6.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TclSOAP-${PORTVERSION}
DISTNAME=	TclSOAP-${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	SOAP and XML-RPC support for TCL library

LICENSE=	MIT

RUN_DEPENDS=	${LOCALBASE}/lib/TclxmlConfig.sh:devel/tclxml

USES=		tcl:wrapper,build
USE_AUTOTOOLS=	autoconf:autoconf
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

.include <bsd.port.mk>
