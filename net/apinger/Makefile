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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/apinger.conf ${PREFIX}/etc/apinger.conf.sample
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
.endif

.include <bsd.port.mk>
