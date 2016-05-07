# Created by: clive
# $FreeBSD$

PORTNAME=	dictd-database
PORTVERSION=	20031009
# clive: Ok, I have no idea how to name this somewhat-meta-port
CATEGORIES=	net textproc
MASTER_SITES=	ftp://ftp.dict.org/dict/pre/
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

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:net/dictd

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKSRC}/*.index ${STAGEDIR}${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${STAGEDIR}${PREFIX}/lib/dict
	@cd ${WRKSRC}/world02-2003-02-15/ && dictzip -k world02.dict
	@${INSTALL_DATA} ${WRKSRC}/world02-2003-02-15/*.index ${STAGEDIR}${PREFIX}/lib/dict
	@${INSTALL_DATA} ${WRKSRC}/world02-2003-02-15/*.dict.dz ${STAGEDIR}${PREFIX}/lib/dict

.include <bsd.port.mk>
