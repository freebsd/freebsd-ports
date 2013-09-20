# Created by: Daisuke Aoyama <aoyama@peach.ne.jp>
# $FreeBSD$

PORTNAME=	openistgt
PORTVERSION=	20120516
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	An iSCSI target for FreeBSD

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFLICTS=	istgt-2*

GNU_CONFIGURE=	yes

MAN1=		istgt.1
MANCOMPRESSED=	yes

ETCDIR=		${PREFIX}/etc/istgt
PLIST_FILES=	bin/istgt \
		bin/istgtcontrol \
		etc/rc.d/openistgt \
		%%ETCDIR%%/auth.conf.sample \
		%%ETCDIR%%/istgt.conf.sample \
		%%ETCDIR%%/istgt.large.conf.sample \
		%%ETCDIR%%/istgtcontrol.conf.sample
PLIST_DIRS=	%%ETCDIR%%
PORTDOCS=	${DOCS:T}

DOCS=		ChangeLog.jp README doc/QUICKSTART doc/QUICKSTART.jp

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} -e '/\/doc\/istgt/d' ${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
