## New ports collection makefile for:    ejabberd
# Date created:                         03 July 2004
# Whom:                                 Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	ejabberd
PORTVERSION=	0.9.1
CATEGORIES=	net
MASTER_SITES=	http://www.jabber.ru/files/ejabberd/ \
		http://www.process-one.net/en/projects/ejabberd/download/${PORTVERSION}/

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/ejabberd ${WRKSRC}/ejabberd.sh
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name \*.orig -or -name \*.bak | ${XARGS} ${RM}

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/ejabberd ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ejabberd.sh ${PREFIX}/etc/rc.d
	@${INSTALL_DATA} ${FILESDIR}/ejabberd.defaults ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/../tools/ejabberdctl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
