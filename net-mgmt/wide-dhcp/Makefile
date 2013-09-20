# Created by: Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
# $FreeBSD$

PORTNAME=	wide-dhcp
PORTVERSION=	1.4.0.7
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/dhcp/wide/
DISTNAME=	dhcp-${PORTVERSION:R}p${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Host Configuration Protocol, WIDE Implementation

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/Copyright

MAKE_ENV=	OSTYPE="${OPSYS}"

MAN5=		dhcpdb.server.5 dhcpdb.pool.5 dhcpdb.relay.5
MAN8=		dhcpc.8 dhcps.8 relay.8 dhcpm.8
DOCS=		README README.jis db_sample/intro.dhcp db_sample/intro.dhcp.jis
EXAMPLES=	dhcpdb.pool dhcpdb.relay dhcpdb.server

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
.for dir in client relay server tools
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^CFLAGS =|CFLAGS +=| ; \
		 s|-O2|| ; \
		 s|^PREFIX =|PREFIX ?=| ; \
		 s|/usr/bin/gzip|/usr/bin/touch|' ${WRKSRC}/${dir}/Makefile.FreeBSD
.endfor

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/wide-dhcps.sh.sample ${PREFIX}/etc/rc.d
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/db_sample && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.mk>
