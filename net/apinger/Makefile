# ex:ts=8
# Ports collection makefile for:  apinger
# Date created:                          Tue Jul 17, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	apinger
PORTVERSION=	0.6.1
CATEGORIES=	net
MASTER_SITES=	http://www.bnet.pl/~jajcus/apinger/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	An IP device monitoring tool

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/apinger.conf ${PREFIX}/etc/apinger.conf.sample
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} "# Please edit ${PREFIX}/etc/apinger.conf to your needs.                       #"
	@${ECHO_MSG} "###############################################################################"
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
.endif

.include <bsd.port.mk>
