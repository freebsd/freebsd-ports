# New ports collection makefile for:    ejabberd
# Date created:                         03 July 2004
# Whom:                                 Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	ejabberd
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://www.jabber.ru/files/ejabberd/

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${DISTNAME}/src
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

# MAN1=		yaws.1
# MAN5=		yaws.conf.5 yaws_api.5

APPDIR=		${PREFIX}/lib/erlang/lib/ejabberd-${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/ejabberd ${WRKSRC}/ejabberdctl ${WRKSRC}/ejabberd.sh
	@${FIND} ${WRKSRC} -name \*.orig -or -name \*.bak | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${APPDIR}/ebin
	@${INSTALL_DATA} ${WRKSRC}/*.beam ${APPDIR}/ebin
	@${RM} -f ${BEAMDIR}/configure.beam
	@${INSTALL_DATA} ${WRKSRC}/*.app ${APPDIR}/ebin
	@${MKDIR} ${APPDIR}/priv/lib
	@${INSTALL_DATA} ${WRKSRC}/*.so  ${APPDIR}/priv/lib
	@${MKDIR} ${APPDIR}/priv/msgs
	@${INSTALL_DATA} ${WRKSRC}/msgs/*.msg ${APPDIR}/priv/msgs
	@${INSTALL_SCRIPT} ${WRKSRC}/ejabberd ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ejabberdctl ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/ejabberd.sh ${PREFIX}/etc/rc.d
	@${INSTALL_DATA} ${FILESDIR}/ejabberd.cfg.sample ${PREFIX}/etc/
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
