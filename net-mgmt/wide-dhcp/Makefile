# New ports collection makefile for:    dhcp
# Version required:     1.3beta
# Date created:         21 November 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.2 1996/05/20 08:06:55 asami Exp $
#

DISTNAME=       dhcp-1.3beta
PKGNAME=        wide-dhcp-1.3b
CATEGORIES+=    net
MASTER_SITES=   ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/lib/libc/stdtime/
DISTFILES=	dhcp-1.3beta.tar.gz tzfile.h
EXTRACT_ONLY=	dhcp-1.3beta.tar.gz

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

MAKE_ENV=	OSTYPE=`uname`

post-patch:
	if [ ! -f ${WRKSRC}/server/tzfile.h ]; then \
		cp ${DISTDIR}/tzfile.h ${WRKSRC}/server/; \
	fi

post-install:
	@if [ ! -d ${PREFIX}/share/dhcp ]; then \
		mkdir -p ${PREFIX}/share/dhcp; \
	fi
	@cp ${WRKSRC}/README ${PREFIX}/share/dhcp/
	@cp ${WRKSRC}/README.jis ${PREFIX}/share/dhcp/
	@cp ${WRKSRC}/db_sample/dhcpdb.pool ${PREFIX}/share/dhcp/dhcpdb.pool.sample
	@cp ${WRKSRC}/db_sample/dhcpdb.relay ${PREFIX}/share/dhcp/dhcpdb.relay.sample
	@cp ${WRKSRC}/db_sample/dhcpdb.server ${PREFIX}/share/dhcp/dhcpdb.server.sample
	@cp ${WRKSRC}/db_sample/intro.dhcp ${PREFIX}/share/dhcp/
	@if [ ! -c /dev/bpf1 ]; then \
	    echo "**********************************************************";\
	    echo "*                      W a r n i n g                     *";\
	    echo "* This DHCP program needs Berkeley packet filter (bpf).  *";\
	    echo "* To use DHCP, your kernel must be rebuilt with bpf, and *";\
	    echo "* make bpf devices on /dev directory.                    *";\
	    echo "* Please read some info file with \`pkg_info ${PKGNAME}'. *";\
	    echo "**********************************************************";\
	fi

.include <bsd.port.mk>
