# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	spinner
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/spinner/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Keep ssh and telnet connections from dropping due to inactivity

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
GNU_CONFIGURE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spinner ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
