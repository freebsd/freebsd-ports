# ex:ts=8
# Ports collection makefile for:  dhcp
# Date created:			  21 November 1995
# Whom:				  Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	wide-dhcp
PORTVERSION=	1.4.0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/wide-dhcp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/dhcp/wide/ \
		ftp://ftp.sage-au.org.au/pub/network/boot/wide-dhcp/
DISTNAME=	dhcp-1.4.0p6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Host Configuration Protocol, WIDE Implementation

MAKE_ENV=	OSTYPE=${OPSYS}

MAN5=		dhcpdb.server.5 dhcpdb.pool.5 dhcpdb.relay.5
MAN8=		dhcpc.8 dhcps.8 relay.8 dhcpm.8
DOCS=		README README.jis db_sample/intro.dhcp db_sample/intro.dhcp.jis
EXAMPLES=	dhcpdb.pool dhcpdb.relay dhcpdb.server

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/wide-dhcps.sh.sample ${PREFIX}/etc/rc.d
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/db_sample && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.mk>
