# New ports collection makefile for:	ifgraph
# Date created:				Sep 18 2003
# Whom:                                 Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	ifgraph
PORTVERSION=	0.4.10
PORTREVISION=	4
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Simple grapher of SNMP data with RRD

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool \
		p5-Color-Rgb>0:${PORTSDIR}/graphics/p5-Color-Rgb \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

USERS=	ifgraph
GROUPS=	ifgraph

PLFILES=	find-if.pl ifgraph.pl makegraph.pl
DOCFILES=	CHANGELOG INSTALACAO INSTALL TODO LICENSE.TXT MUDANCAS

SUB_FILES=	crontab pkg-deinstall pkg-install pkg-message
SUB_LIST=	USER=${USERS} PERL=${PERL}

do-install:
.for plfile in ${PLFILES}
	@ ${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/${plfile} > ${WRKDIR}/${plfile}
	@ ${INSTALL_SCRIPT} ${WRKDIR}/${plfile} ${PREFIX}/bin
.endfor
	@ ${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/ifgraph.conf > ${WRKSRC}/ifgraph.conf.sample
	@ ${INSTALL_DATA} ${WRKSRC}/ifgraph.conf.sample ${PREFIX}/etc
	@ ${MKDIR} ${PREFIX}/ifgraph
	@ ${MKDIR} ${PREFIX}/ifgraph/htdocs
	@ ${MKDIR} ${PREFIX}/ifgraph/lib
	@ ${CP} ${WRKSRC}/lib/rgb.txt ${PREFIX}/ifgraph/lib
	@ ${CP} -Rp ${WRKSRC}/templates ${PREFIX}/ifgraph
	@ ${INSTALL_DATA} ${WRKDIR}/crontab ${PREFIX}/ifgraph/crontab
	@ ${CHOWN} -R ifgraph:ifgraph ${PREFIX}/ifgraph
	@ ${MKDIR} ${PREFIX}/var/ifgraph
	@ ${CHOWN} ifgraph:ifgraph ${PREFIX}/var/ifgraph
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

post-install:
	@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
