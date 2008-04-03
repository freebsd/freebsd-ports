# New ports collection makefile for:	fpkg
# Date created:		28 January 2006
# Whom:			Yuki SHIMAZU  <y.shimazu@nifty.com>
#
# $FreeBSD$
#

PORTNAME=	fpkg
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://voodoo.bawue.com/download/ \
		http://www.shimazu.org/fpkg/
DISTFILES=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	y.shimazu@nifty.com
COMMENT=	Package Tool Wrapper for FreeBSD

USE_PERL5=	YES
NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/fpkg

do-install:
	@${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
