# New ports collection makefile for:	dnews
# Version required:     27q
# Date created:		Sa  22 Feb 1997 14:38:05 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.1.1.1 1997/02/22 14:56:45 andreas Exp $
#

DISTNAME=	dnews
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.netwinsite.com/pub/netwinsite/dnews/oldversions/
DISTFILES=	dnews27q_freebsd.tar.Z

MAINTAINER=	andreas@FreeBSD.ORG

NO_CDROM=	"have to ask the company, if we are allowed to put it on CDROM"
RESTRICTED=	"only free for non-profit organis. like schools + universities"
NO_PACKAGE=	"we are not allowed, sorry"

# dnewsweb is a cgi program that allows you to read and post news through 
# your WWW Navigator of your choice, so that you don't need a special 
# news reader. Default is, not to install dnewsweb.

pre-fetch:
.if !defined(DNEWSWEB)
	@${ECHO} "Install with dnewsweb cgi script, that enables you to "
	@${ECHO} "read and post news using a Web Browser of your choice"
	@${ECHO} "by typing \"make DNEWSWEB=yes install\"."
.else
	@${ECHO} "Installing with dnewsweb support"
RUN_DEPENDS=	${PREFIX}/sbin/httpd:${PORTSDIR}/www/apache
.endif

# nothing to make, binary only
NO_BUILD=		yes

# dnews' install script installs with too restrictive permissions
# (only rwx for the owner news) and installs unneeded stuff into 
# the library directory, therefore I rearranged the installation:

INST_PRG=${INSTALL} ${COPY} ${STRIP} -o news -g news -m 550
INST_SCR=${INSTALL} ${COPY} -o news -g news -m 554
INST_DAT=${INSTALL} ${COPY} -o news -g news -m 644

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tellnews ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/dnews
	@chown news.news ${PREFIX}/dnews
	@chmod 0755 ${PREFIX}/dnews
	@${INST_PRG} ${WRKSRC}/dnews ${PREFIX}/dnews
	@${INST_PRG} ${WRKSRC}/dnews_start ${PREFIX}/dnews
	@${INST_PRG} ${WRKSRC}/dposter ${PREFIX}/dnews
	@${INST_PRG} ${WRKSRC}/xmit ${PREFIX}/dnews
	@${INST_SCR} ${WRKSRC}/fixowner.sh ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/access.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/control.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/dnews.conf ${PREFIX}/etc
	@ln -sf ${PREFIX}/etc/dnews.conf /etc
	@${INST_DAT} ${WRKSRC}/expire.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/fts.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/moderators.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/newsfeeds.conf ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/nocached.body ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/nocached.head ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/install.txt ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/license.txt ${PREFIX}/dnews
	@${INST_DAT} ${WRKSRC}/manual.txt ${PREFIX}/dnews
	@${MKDIR} /var/spool/dnews
	@chown news.news /var/spool/dnews
	@chmod 755 /var/spool/dnews
	@${INSTALL_SCRIPT} ${FILESDIR}/dnews.sh ${PREFIX}/etc/rc.d
.if defined(DNEWSWEB)
	@${INSTALL_PROGRAM} ${WRKSRC}/dnewsweb ${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/dnewsweb.ini ${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/dnewsweb.txt ${PREFIX}/www/cgi-bin
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*** DNEWS is NOT free !!!"
	@${ECHO_MSG} "*** Please read ${PREFIX}/dnews/license.txt"
	@${ECHO_MSG} "*** Edit the following config files before use:"
	@${ECHO_MSG} "/etc/dnews.conf, ${PREFIX}/dnews/*.conf"
.if defined(DNEWSWEB)
	@${ECHO_MSG} "and ${PREFIX}/www/cgi-bin/dnewsweb.ini !"
.endif

.include <bsd.port.mk>
