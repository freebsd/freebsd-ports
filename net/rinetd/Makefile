# New ports collection makefile for:	rinetd
# Date created:				23 Dec 1997
# Whom:					alexp
#
# $FreeBSD$
#

PORTNAME=	rinetd
PORTVERSION=	0.62
CATEGORIES=	net
MASTER_SITES=	http://www.boutell.com/rinetd/http/
DISTNAME=	rinetd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple TCP port redirector

WRKSRC=		${WRKDIR}/rinetd/

MAN8=		rinetd.8
PORTDOCS=	index.html
PLIST_FILES=	etc/rc.d/rinetd.sh sbin/rinetd


USE_RC_SUBR=	yes
RC_SCRIPTS_SUB= PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/rinetd.sh > ${WRKDIR}/rinetd.sh

post-install:
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/rinetd.sh ${PREFIX}/etc/rc.d/rinetd.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
