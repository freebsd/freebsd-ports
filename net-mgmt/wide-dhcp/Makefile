# New ports collection makefile for:    dhcp
# Version required:     1.4.0p1
# Date created:         21 November 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

DISTNAME=       dhcp-1.4.0p6
PKGNAME=        wide-dhcp-1.4.0p6
CATEGORIES=     net
MASTER_SITES=   ftp://sh.wide.ad.jp/WIDE/free-ware/dhcp/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/wide-dhcp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/dhcp/wide/ \
		ftp://ftp.sage-au.org.au/pub/network/boot/wide-dhcp/

MAINTAINER=     obrien@FreeBSD.org

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
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";	\
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT};			\
		${ECHO} 'DB_POOL=/etc/dhcpdb.pool' >> ${STARTUP_SCRIPT};	\
		${ECHO} 'DB_RELAY=/etc/dhcpdb.relay' >> ${STARTUP_SCRIPT};	\
		${ECHO} 'DB_BIND=/var/db/dhcpdb.bind' >> ${STARTUP_SCRIPT};\
		${ECHO} 'if [ -f $${DB_POOL} -a -f $${DB_RELAY} \'\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} '		-a -x ${PREFIX}/sbin/dhcps ]; then'	\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} '	if [ -f $${DB_BIND} ]; then' >> ${STARTUP_SCRIPT};\
		${ECHO} '		find $${DB_POOL} -newer $${DB_BIND} -exec ${RM} $${DB_BIND} \;'\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} '	fi' >> ${STARTUP_SCRIPT};			\
		${ECHO} "	${PREFIX}/sbin/dhcps [Interface Name]"		\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} "	${ECHO} -n ' dhcps'"				\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} 'fi' >> ${STARTUP_SCRIPT};				\
		${CHMOD} 755 ${STARTUP_SCRIPT};				\
		${CHOWN} bin.bin ${STARTUP_SCRIPT};                        \
	fi
	@if [ ! -c /dev/bpf1 ]; then \
	    ${ECHO} "**********************************************************";\
	    ${ECHO} "*                      W a r n i n g                     *";\
	    ${ECHO} "* This DHCP program needs Berkeley packet filter (bpf).  *";\
	    ${ECHO} "* To use DHCP, your kernel must be rebuilt with bpf, and *";\
	    ${ECHO} "* make bpf devices on /dev directory.                    *";\
	    ${ECHO} "* Please read some info file with \`pkg_info ${PKGNAME}'. *";\
	    ${ECHO} "**********************************************************";\
	fi

.include <bsd.port.mk>
