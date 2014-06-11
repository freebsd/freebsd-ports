# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	popular
PORTVERSION=	1.5.5
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.remote.org/jochen/mail/popular/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of programs for setting up large POP3 server systems

BUILD_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM

CONFLICTS=	pserv-[0-9]* synce-librapi2-[0-9]*

USES=		libtool perl5 gmake
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
PDM_MODULES=	any master
CONFIGURE_ARGS=	--without-bdb --disable-docbook --with-confdir=${PREFIX}/etc/popular \
		--enable-ssl --with-pdm="${PDM_MODULES}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USE_RC_SUBR=	pcheckd pproxy pserv 0ringd

OPTIONS_DEFINE=	DB4
OPTIONS_DEFAULT=	DB4
OPTIONS_SUB=	yes

DB4_DESC=	Build db4 pdm module
DB4_LIB_DEPENDS=	libdb4.so:${PORTSDIR}/databases/db4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDB4}
PDM_MODULES+=	db4
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/pproxy.rc ${STAGEDIR}${ETCDIR}/pproxy.rc.sample
	${INSTALL_DATA} ${WRKSRC}/conf/pserv.rc ${STAGEDIR}${ETCDIR}/pserv.rc.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/popular
	${FIND} ${WRKSRC}/src -name *.h | ${XARGS} -n 1 -J % ${INSTALL_DATA} % \
		${STAGEDIR}${PREFIX}/include/popular

.include <bsd.port.mk>
