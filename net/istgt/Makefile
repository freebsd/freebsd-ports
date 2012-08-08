# New ports collection makefile for:	istgt
# Date created:		2009-02-23
# Whom:			Daisuke Aoyama <aoyama@peach.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	istgt
PORTVERSION=	20120807
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/

MAINTAINER=	aoyama@peach.ne.jp
COMMENT=	An iSCSI target for FreeBSD

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes

MAN1=		istgt.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/istgt \
		bin/istgtcontrol \
		etc/rc.d/istgt \
		%%ETCDIR%%/auth.conf.sample \
		%%ETCDIR%%/istgt.conf.sample \
		%%ETCDIR%%/istgt.large.conf.sample \
		%%ETCDIR%%/istgtcontrol.conf.sample
PLIST_DIRS=	%%ETCDIR%%
PORTDOCS=	${DOCS:T}

DOCS=		ChangeLog.jp README doc/QUICKSTART doc/QUICKSTART.jp

post-extract:
	@${REINPLACE_CMD} -e '/\/doc\/istgt/d' ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
