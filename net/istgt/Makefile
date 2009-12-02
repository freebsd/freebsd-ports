# New ports collection makefile for:	istgt
# Date created:		2009-02-23
# Whom:			Daisuke Aoyama <aoyama@peach.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	istgt
PORTVERSION=	20091130
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/

MAINTAINER=	aoyama@peach.ne.jp
COMMENT=	An iSCSI target for FreeBSD 7.x

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes

MAN1=		istgt.1
MANCOMPRESSED=	yes

PORTDOCS=	README ChangeLog.jp QUICKSTART QUICKSTART.jp

post-extract:
	@${MV} ${WRKSRC}/doc/Makefile.in ${WRKSRC}/doc/Makefile.tmp
	@${SED} -e '/\/doc\/istgt/d' < ${WRKSRC}/doc/Makefile.tmp \
		> ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog.jp ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/QUICKSTART ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/QUICKSTART.jp ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
