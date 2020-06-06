# Created by: M. Birgmeier
# $FreeBSD$

PORTNAME=	libiscsi
DISTVERSION=	1.19.0
CATEGORIES=	net

MAINTAINER=	d8zNeCFG@aon.at
COMMENT=	Client-side library to implement the iSCSI protocol

LICENSE=		LGPL21+ GPLv2+
LICENSE_COMB=		multi
LICENSE_FILE_LGPL21+  =	${WRKSRC}/LICENCE-LGPL-2.1.txt
LICENSE_FILE_GPLv2+   =	${WRKSRC}/LICENCE-GPL-2.txt

USES=		autoreconf compiler:c11 libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	sahlberg

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
