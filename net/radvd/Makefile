# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	radvd
PORTVERSION=	1.9.7
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.litech.org/radvd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux/BSD IPv6 router advertisement daemon

LIB_DEPENDS=	libdaemon.so:${PORTSDIR}/devel/libdaemon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=
USES=		pkgconfig gmake
USE_RC_SUBR=	radvd

PORTDOCS=	CHANGES COPYRIGHT INTRO.html README TODO

post-install:
	@${INSTALL_DATA} ${WRKSRC}/radvd.conf.example ${STAGEDIR}${PREFIX}/etc/
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S.^.${WRKSRC}/.} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
