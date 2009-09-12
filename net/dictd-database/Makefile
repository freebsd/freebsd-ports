# ex:ts=8
# New ports collection makefile for:	dictd-database
# Date created:		Jan 29, 2001
# Whom:			clive
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	20031009
# clive: Ok, I have no idea how to name this somewhat-meta-port
CATEGORIES=	net textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/pre/
DISTFILES=	devils-dict-pre.tar.gz \
		dict-foldoc-20030927-pre.tar.gz \
		dict-gazetteer-1.2-pre.tar.gz \
		dict-gcide-0.44.tar.gz \
		dict-jargon_4.3.1.tgz \
		dict-misc-1.5b-pre.tar.gz \
		dict-vera-1.9-pre.tar.gz \
		dict-web1913-1.4-pre.tar.gz \
		dict-wn-2.0-pre.tar.gz \
		dict-world02-20030215.tar.gz \
		elements-20001107-pre.tar.gz

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Dictd words database

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:${PORTSDIR}/net/dictd

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BROKEN=		checksum mismatch

do-install:
	@${MKDIR} ${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKDIR}/*.index ${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKDIR}/*.dict* ${PREFIX}/lib/dict
	cd ${WRKDIR}/world02-2003-02-15/ && dictzip world02.dict
	@${INSTALL_DATA} ${WRKDIR}/world02-2003-02-15/*.index ${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKDIR}/world02-2003-02-15/*.dict* ${PREFIX}/lib/dict

.include <bsd.port.mk>
