# Created by: jkh
# $FreeBSD$

PORTNAME=	sup
PORTVERSION=	2.0.20140517
CATEGORIES=	net
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	CMU's Software Update Protocol package

LICENSE=	ISCL
LICENSE_FILE=	${FILESDIR}/COPYING

MAKE_ARGS+=	-DWITH_INSTALL_AS_USER
PLIST_FILES=	bin/sup bin/supfilesrv bin/supscan \
		man/man1/sup.1.gz man/man8/supfilesrv.8.gz \
		man/man8/supscan.8.gz man/man8/supservers.8.gz

.include <bsd.port.mk>
