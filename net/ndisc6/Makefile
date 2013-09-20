# Created by: rdenis@simphalempin.com
# $FreeBSD$

PORTNAME=	ndisc6
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.remlab.net/files/ndisc6/ \
		http://people.via.ecp.fr/~rem/www.remlab.net/files/ndisc6/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	IPv6 network diagnostic tools

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-suid-install

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} >= 803000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rdnssd-rdnssd.h
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CONFIGURE_ARGS+=--disable-nls
.endif

MAN1=		addr2name.1 dnssort.1 tcpspray.1
MAN8=		ndisc6.8 rdisc6.8 rdnssd.8 rltraceroute6.8
MLINKS=		rltraceroute6.8 tcptraceroute6.8 \
		rltraceroute6.8 tracert6.8 \
		addr2name.1 name2addr.1 \
		tcpspray.1 tcpspray6.1

USE_RC_SUBR=	rdnssd

PORTDOCS=	AUTHORS NEWS README

post-install:
.if	${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
