## New ports collection makefile for:    ejabberd
# Date created:                         03 July 2004
# Whom:                                 Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	ejabberd
PORTVERSION=	1.1.1
CATEGORIES=	net-im
MASTER_SITES=	http://www.process-one.net/en/projects/ejabberd/download/${PORTVERSION}/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	shaun@inerd.com
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}.sh
NOPRECIOUSMAKEVARS=	yes

MAKE_ENV=	PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

pre-install:
	${FIND} ${WRKSRC} '(' -name \*.orig -or -name \*.bak ')' -delete

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${WRKSRC}/../tools/${PORTNAME}ctl ${PREFIX}/bin

	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.defaults ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.defaults.example
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.inetrc ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.inetrc.example
.if !exists(${PREFIX}/etc/${PORTNAME}/${PORTNAME}.inetrc)
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.inetrc ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.inetrc
.endif

	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
