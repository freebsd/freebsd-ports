# ex:ts=8
# Ports collection makefile for:  newspost
# Date created:                          Tue Jul 23, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	newspost
PORTVERSION=	2.0
CATEGORIES=	news
MASTER_SITES=	http://newspost.unixcab.org/download/

MAINTAINER=	mich@freebsdcluster.org

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

USE_REINPLACE=  yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
		-e "s|^OPT_FLAGS|#OPT_FLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/man1/newspost.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

MAN1=           newspost.1

.include <bsd.port.mk>
