# ex:ts=8
# Ports collection makefile for:  apinger
# Date created:                          Tue Jul 17, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	apinger
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	http://www.bnet.pl/~jajcus/apinger/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@freebsdcluster.org

GNU_CONFIGURE=	yes

DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/apinger.conf ${PREFIX}/etc/
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "###############################################################################"
	@${ECHO} "# Please edit ${PREFIX}/etc/apinger.conf to your needs.                       #"
	@${ECHO} "###############################################################################"
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
.endif
.include <bsd.port.mk>
