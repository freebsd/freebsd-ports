# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	apinger
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		http://www.bnet.pl/~jajcus/apinger/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	An IP device monitoring tool

GNU_CONFIGURE=	yes
USE_RC_SUBR=	apinger
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	IPV6

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/apinger.conf ${STAGEDIR}${PREFIX}/etc/apinger.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/AUTHORS

.include <bsd.port.mk>
