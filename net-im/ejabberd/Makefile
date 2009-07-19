## New ports collection makefile for:    ejabberd
# Date created:                         03 July 2004
# Whom:                                 Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	ejabberd
PORTVERSION=	2.0.5
CATEGORIES=	net-im
MASTER_SITES=	http://www.process-one.net/downloads/ejabberd/${PORTVERSION}/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes

OPTIONS=	ODBC	"Enable ODBC support"		off

MAKE_ENV=	PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message pkg-install
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.pre.mk>

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=--enable-odbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/../doc/ && ${INSTALL_DATA} COPYING *.html *.png *.txt ${DOCSDIR})
.endif

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
