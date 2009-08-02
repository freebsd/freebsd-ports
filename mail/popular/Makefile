# New ports collection makefile for:	popular
# Date created:				11 July 2005
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	popular
PORTVERSION=	1.5.5
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.remote.org/jochen/mail/popular/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Suite of programs for setting up large POP3 server systems

BUILD_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes
PDM_MODULES=	any master
CONFIGURE_ARGS=	--without-bdb --disable-docbook --with-confdir=${PREFIX}/etc/popular \
		--enable-ssl --with-pdm="${PDM_MODULES}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

USE_RC_SUBR=	pcheckd.sh pproxy.sh pserv.sh 0ringd.sh

MAN1=		pcheck.1 pcontrol.1 pdeliver.1 pstatus.1 ptestpdm.1
MAN7=		popular-log.7
MAN8=		pcheckd.8 pproxy.8 pserv.8 ringd.8

OPTIONS=	DB4 "Build db4 pdm module" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DB4)
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
PLIST_SUB+=	WITH_DB4=""
PDM_MODULES+=	db4
.else
PLIST_SUB+=	WITH_DB4="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/popular
	${INSTALL_DATA} ${WRKSRC}/conf/pproxy.rc ${PREFIX}/etc/popular/pproxy.rc.sample
	${INSTALL_DATA} ${WRKSRC}/conf/pserv.rc ${PREFIX}/etc/popular/pserv.rc.sample
	${MKDIR} ${PREFIX}/include/popular
	${FIND} ${WRKSRC}/src -name *.h | ${XARGS} -n 1 -J % ${INSTALL_DATA} % ${PREFIX}/include/popular

.include <bsd.port.post.mk>
