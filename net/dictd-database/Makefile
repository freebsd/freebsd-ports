# ex:ts=8
# New ports collection makefile for:	dictd-database
# Date created:		Jan 29, 2001
# Whom:			clive
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	20010130
# clive: Ok, I have no idea how to name this somewhat-meta-port
CATEGORIES=	net textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/pre/
DISTFILES=	devils-dict-pre.tar.gz dict-gazetteer-1.2-pre.tar.gz \
		jargon-4.2.3.tar.gz \
		dict-misc-1.5b-pre.tar.gz dict-web1913-1.4-pre.tar.gz \
		dict-wn-1.5-pre.tar.gz foldoc_20010119.tar.gz

MAINTAINER=	ijliao@FreeBSD.org

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKDIR}/* ${PREFIX}/lib/dict

.include <bsd.port.mk>
