# ex:ts=8
# New ports collection makefile for:	spinner
# Date created:			Dec 16, 2002
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	spinner
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/spinner/

MAINTAINER=	mich@freebsdcluster.org

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g ; \
		s|gcc |\$$\(CC\) |g' ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spinner ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
