# ex:ts=8
# Ports collection makefile for:  dhcp
# Date created:			  21 November 1995
# Whom:				  Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	wide-dhcp
PORTVERSION=	1.4.0.6
CATEGORIES=	net
MASTER_SITES=	ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/wide-dhcp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/dhcp/wide/ \
		ftp://ftp.sage-au.org.au/pub/network/boot/wide-dhcp/
DISTNAME=	dhcp-1.4.0p6

MAINTAINER=	ports@FreeBSD.org

MAKE_ENV=	OSTYPE=${OPSYS}

MAN5=	dhcpdb.server.5 dhcpdb.pool.5 dhcpdb.relay.5
MAN8=	dhcpc.8 dhcps.8 relay.8 dhcpm.8

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/wide-dhcps.sh.sample

post-install:
.if !defined(NOPORTDOCS)
	@if [ ! -d ${PREFIX}/share/doc/dhcp ]; then \
		${MKDIR} ${PREFIX}/share/doc/dhcp; \
	fi
	@if [ ! -d ${PREFIX}/share/examples/dhcp ]; then \
		${MKDIR} ${PREFIX}/share/examples/dhcp; \
	fi
	@${CP} ${WRKSRC}/README ${PREFIX}/share/doc/dhcp/
	@${CP} ${WRKSRC}/README.jis ${PREFIX}/share/doc/dhcp/
	@${CP} ${WRKSRC}/db_sample/dhcpdb.pool  \
		${PREFIX}/share/examples/dhcp/dhcpdb.pool.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.relay  \
		${PREFIX}/share/examples/dhcp/dhcpdb.relay.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.server  \
		${PREFIX}/share/examples/dhcp/dhcpdb.server.sample
	@${CP} ${WRKSRC}/db_sample/intro.dhcp ${PREFIX}/share/doc/dhcp/
	@${CP} ${WRKSRC}/db_sample/intro.dhcp.jis  \
		${PREFIX}/share/doc/dhcp/
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				    \
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";	    \
		${INSTALL_SCRIPT} ${FILESDIR}/wide-dhcps.sh.sample ${STARTUP_SCRIPT}; \
	fi
	@if [ ! -c /dev/bpf1 ]; then \
	    ${ECHO} "********************************************************";\
	    ${ECHO} "*                   W a r n i n g                      *";\
	    ${ECHO} "* DHCP the needs Berkeley Packet Filter (bpf).         *";\
	    ${ECHO} "* To use DHCP, your kernel must be rebuilt with bpf,   *";\
	    ${ECHO} "* and make bpf devices on /dev directory.              *";\
	    ${ECHO} "* Please read the info file by \`pkg_info ${PKGNAME}'. *";\
	    ${ECHO} "********************************************************";\
	fi

.include <bsd.port.mk>
