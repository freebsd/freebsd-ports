# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sslh
PORTVERSION=	1.15
CATEGORIES=	net
MASTER_SITES=	http://www.rutschle.net/tech/

MAINTAINER=	olivier@cochard.me
COMMENT=	SSL/SSH multiplexer

LICENSE=	GPLv2

LIB_DEPENDS=	libconfig.so:${PORTSDIR}/devel/libconfig

USES=		gmake perl5
USE_PERL5=	build

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PLIST_FILES=	sbin/sslh-fork \
		sbin/sslh-select \
		etc/sslh.conf.sample \
		man/man8/sslh.8.gz

USE_RC_SUBR=	sslh

PORTEXAMPLES=	example.cfg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/basic.cfg ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_MAN} ${WRKSRC}/sslh.8.gz ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
