# New ports collection makefile for:   ompload
# Date created:        3 December 2009
# Whom:                Philippe Pepiot
#
# $FreeBSD$
#

PORTNAME=	ompload
PORTVERSION=	1
CATEGORIES=	www
MASTER_SITES=	http://omploader.org/
DISTNAME=	ompload
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	phil@philpep.org
COMMENT=	Upload files to omploader.org

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_RUBY=	yes

NO_MAN=		yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ompload

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/ompload ${PREFIX}/bin/ompload

.include <bsd.port.mk>
