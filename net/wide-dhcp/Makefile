# New ports collection makefile for:    dhcp
# Version required:     1.4.0p1
# Date created:         21 November 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.14 1998/12/05 11:24:05 obrien Exp $
#

DISTNAME=       dhcp-1.4.0p5
PKGNAME=        wide-dhcp-1.4.0p5
CATEGORIES=     net
MASTER_SITES=   ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/wide-dhcp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/dhcp/wide/ \
		ftp://ftp.sage-au.org.au/pub/network/boot/wide-dhcp/

MAINTAINER=     hideyuki@sat.t.u-tokyo.ac.jp

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
	@${CP} ${WRKSRC}/db_sample/dhcpdb.pool ${PREFIX}/share/examples/dhcp/dhcpdb.pool.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.relay ${PREFIX}/share/examples/dhcp/dhcpdb.relay.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.server ${PREFIX}/share/examples/dhcp/dhcpdb.server.sample
	@${CP} ${WRKSRC}/db_sample/intro.dhcp ${PREFIX}/share/doc/dhcp/
	@${CP} ${WRKSRC}/db_sample/intro.dhcp.jis ${PREFIX}/share/doc/dhcp/
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		echo "Installing ${STARTUP_SCRIPT} startup file.";	\
		echo '#!/bin/sh' > ${STARTUP_SCRIPT};			\
		echo 'DB_POOL=/etc/dhcpdb.pool' >> ${STARTUP_SCRIPT};	\
		echo 'DB_RELAY=/etc/dhcpdb.relay' >> ${STARTUP_SCRIPT};	\
		echo 'DB_BIND=/var/db/dhcpdb.bind' >> ${STARTUP_SCRIPT};\
		echo 'if [ -f $${DB_POOL} -a -f $${DB_RELAY} \'\
			>> ${STARTUP_SCRIPT};				\
		echo '		-a -x /usr/local/sbin/dhcps ]; then'	\
			>> ${STARTUP_SCRIPT};				\
		echo '	if [ -f $${DB_BIND} ]; then' >> ${STARTUP_SCRIPT};\
		echo '		find $${DB_POOL} -newer $${DB_BIND} -exec rm $${DB_BIND} \;'\
			>> ${STARTUP_SCRIPT};				\
		echo '	fi' >> ${STARTUP_SCRIPT};			\
		echo "	${PREFIX}/sbin/dhcps [Interface Name]"		\
			>> ${STARTUP_SCRIPT};				\
		echo "	echo -n ' dhcps'"				\
			>> ${STARTUP_SCRIPT};				\
		echo 'fi' >> ${STARTUP_SCRIPT};				\
		chmod 755 ${STARTUP_SCRIPT};				\
		chown bin.bin ${STARTUP_SCRIPT};                        \
	fi
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
