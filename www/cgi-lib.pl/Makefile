# Created by: sada
# $FreeBSD$

PORTNAME=	cgi-lib_pl
PORTVERSION=	2.18
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
DISTNAME=	cgi-lib.pl-${PORTVERSION}
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	De facto standard library for creating CGI in perl

USES=		perl5
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_FILES=	%%SITE_PERL%%/cgi-lib.pl
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> cgi-lib.pl

INSTALL_BASE=	${SITE_PERL_REL}
INSTALL_DIR=	${PREFIX}/${INSTALL_BASE}

NO_STAGE=	yes
do-install:
	-${MKDIR} ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKDIR}/cgi-lib.pl ${INSTALL_DIR}

.include <bsd.port.mk>
