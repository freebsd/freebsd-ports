PORTNAME=	openbsm
DISTVERSION=	1.1-p2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.trustedbsd.org/downloads/
DISTNAME=	openbsm-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Basic Security Module (BSM) Audit Implementation
WWW=		http://www.trustedbsd.org/openbsm.html

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

CONFLICTS=	openbsm-devel-1.[0-9]*

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		libtool tar:tgz
USE_LDCONFIG=	yes

.include <bsd.port.mk>
