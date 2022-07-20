PORTNAME=	popular
PORTVERSION=	1.5.5
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	https://www.jochentopf.com/software/popular/

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Suite of programs for setting up large POP3 server systems

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-DOM>=0:textproc/p5-XML-DOM

USES=		libtool perl5 gmake tar:bzip2 ssl
CONFLICTS=	pserv synce-librapi2
CONFLICTS_INSTALL=	ports-tools # bin/pcheck

GNU_CONFIGURE=	yes
PDM_MODULES=	any master
CONFIGURE_ARGS=	--without-bdb --disable-docbook --with-confdir=${PREFIX}/etc/popular \
		--enable-ssl --with-pdm="${PDM_MODULES}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USE_RC_SUBR=	pcheckd pproxy pserv 0ringd
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/popular/*.so
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/pproxy.rc ${STAGEDIR}${ETCDIR}/pproxy.rc.sample
	${INSTALL_DATA} ${WRKSRC}/conf/pserv.rc ${STAGEDIR}${ETCDIR}/pserv.rc.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/popular
	${FIND} ${WRKSRC}/src -name *.h | ${XARGS} -n 1 -J % ${INSTALL_DATA} % \
		${STAGEDIR}${PREFIX}/include/popular

.include <bsd.port.mk>
