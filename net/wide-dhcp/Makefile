# New ports collection makefile for:    dhcp
# Version required:     1.3beta
# Date created:         21 November 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.8 1997/04/04 02:19:46 brian Exp $
#

DISTNAME=       dhcp-1.3beta
PKGNAME=        wide-dhcp-1.3b
CATEGORIES=     net
MASTER_SITES=   ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/FreeBSD-current/src/lib/libc/stdtime/
DISTFILES=	dhcp-1.3beta.tar.gz tzfile.h

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

EXTRACT_ONLY=	dhcp-1.3beta.tar.gz
IGNOREFILES=	tzfile.h
MAKE_ENV=	OSTYPE=`uname`

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/wide-dhcps.sh.sample

post-patch:
	if [ ! -f ${WRKSRC}/server/tzfile.h ]; then \
		${CP} ${DISTDIR}/tzfile.h ${WRKSRC}/server/; \
	fi

post-install:
	@if [ ! -d ${PREFIX}/share/dhcp ]; then \
		${MKDIR} ${PREFIX}/share/dhcp; \
	fi
	@${CP} ${WRKSRC}/README ${PREFIX}/share/dhcp/
	@${CP} ${WRKSRC}/README.jis ${PREFIX}/share/dhcp/
	@${CP} ${WRKSRC}/db_sample/dhcpdb.pool ${PREFIX}/share/dhcp/dhcpdb.pool.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.relay ${PREFIX}/share/dhcp/dhcpdb.relay.sample
	@${CP} ${WRKSRC}/db_sample/dhcpdb.server ${PREFIX}/share/dhcp/dhcpdb.server.sample
	@${CP} ${WRKSRC}/db_sample/intro.dhcp ${PREFIX}/share/dhcp/
	@${CP} ${WRKSRC}/db_sample/intro.dhcp.jis ${PREFIX}/share/dhcp/
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
		echo "	${PREFIX}/sbin/dhcps [Intarface Name]"		\
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
