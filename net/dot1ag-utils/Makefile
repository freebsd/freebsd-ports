PORTNAME=	dot1ag-utils
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	https://git.sr.ht/~bms/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Utilities for IEEE 802.1ag Connectivity Fault Management
WWW=		https://github.com/vnrick/dot1ag-utils

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USE_RC_SUBR=	dot1ag_ccd dot1agd

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	DOCS MANPAGES
OPTIONS_SUB=            yes

.include <bsd.port.mk>
