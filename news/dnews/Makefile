# New ports collection makefile for:	dnews
# Version required:     42j
# Date created:		Thu May 29 17:16:36 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1997/08/17 10:36:44 andreas Exp $
#

DISTNAME=	dnews
PKGNAME=	dnews-4.3f
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.netwinsite.com/pub/netwinsite/dnews/
DISTFILES=	dnews43f_freebsd.tar.Z

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
	${MKDIR} ${PREFIX}/lib/dnews/scripts
	${MKDIR} ${PREFIX}/lib/dnews/doc
		@chmod -R 0755 ${PREFIX}/lib/dnews
		@chown -R news.news ${PREFIX}/lib/dnews
	${MKDIR} /var/log/dnews
		@chmod 0755 /var/log/dnews
		@chown news.news /var/log/dnews
	${MKDIR} /var/spool/dnews
		@chmod 0755 /var/spool/dnews
		@chown news.news /var/spool/dnews
	@${ECHO_MSG} ">> Installing tellnews control program in ${PREFIX}/bin"
	@${INSTALL_PROGRAM} ${WRKSRC}/tellnews \
				${PREFIX}/bin
	@${ECHO_MSG} ">> Installing runtime programs in ${PREFIX}/lib/dnews"
	@${INST_PRG} ${WRKSRC}/dnews \
				${PREFIX}/lib/dnews
	@${INST_PRG} ${WRKSRC}/dnews_start \
				${PREFIX}/lib/dnews
	@${INST_PRG} ${WRKSRC}/dposter \
				${PREFIX}/lib/dnews
	@${INST_PRG} ${WRKSRC}/xmit \
				${PREFIX}/lib/dnews
	@${INST_DAT} ${WRKSRC}/nocached.body \
				${PREFIX}/lib/dnews
	@${INST_DAT} ${WRKSRC}/nocached.head \
				${PREFIX}/lib/dnews
	@${ECHO_MSG} ">> Installing scripts in ${PREFIX}/lib/dnews/scripts"
	@${INST_SCR} ${WRKSRC}/newver.sh ${PREFIX}/lib/dnews/scripts
	@${ECHO_MSG} ">> Installing config files in ${PREFIX}/lib/dnews"
	@${INST_DAT} ${WRKSRC}/access.conf \
				${PREFIX}/lib/dnews/access.conf.sample
	@${INST_DAT} ${WRKSRC}/control.conf \
				${PREFIX}/lib/dnews/control.conf.sample
	@${INST_DAT} ${WRKSRC}/dnews.conf \
				${PREFIX}/lib/dnews/dnews.conf.sample
	@ln -sf ${PREFIX}/lib/dnews/dnews.conf /etc
	@${INST_DAT} ${WRKSRC}/expire.conf \
				${PREFIX}/lib/dnews/expire.conf.sample
	@${INST_DAT} ${WRKSRC}/fts.conf \
				${PREFIX}/lib/dnews/fts.conf.sample
	@ln -sf ${PREFIX}/lib/dnews/fts.conf /var/spool/dnews/fts.conf
	@${INST_DAT} ${WRKSRC}/hp.conf \
				${PREFIX}/lib/dnews/hp.conf.sample
	@${INST_DAT} ${WRKSRC}/moderators.conf \
				${PREFIX}/lib/dnews/moderators.conf.sample
	@${INST_DAT} ${WRKSRC}/newsfeeds.conf \
				${PREFIX}/lib/dnews/newsfeeds.conf.sample
	@${ECHO_MSG} ">> Installing doc files in ${PREFIX}/etc/dnews/doc"
	@${INST_DAT} ${WRKSRC}/install.txt \
				${PREFIX}/lib/dnews/doc
	@${INST_DAT} ${WRKSRC}/license.txt \
				${PREFIX}/lib/dnews/doc
	@${INST_DAT} ${WRKSRC}/manual.txt \
				${PREFIX}/lib/dnews/doc
	@${INST_DAT} ${FILESDIR}/faq.html \
				${PREFIX}/lib/dnews/doc
	@${ECHO_MSG} ">> Installing doc files in ${PREFIX}/etc/rc.d"
	@${INST_SCR} ${FILESDIR}/dnews.sh \
				${PREFIX}/etc/rc.d
.if defined(DNEWSWEB)
	@${INSTALL_PROGRAM} ${WRKSRC}/dnewsweb ${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/dnewsweb.ini ${PREFIX}/www/cgi-bin
	@${INSTALL_DATA} ${WRKSRC}/dnewsweb.txt ${PREFIX}/www/cgi-bin
.endif
	@${ECHO_MSG} "*** DNEWS is NOT free !!!"
	@${ECHO_MSG} "*** Please read ${PREFIX}/lib/dnews/doc/license.txt"
	@${ECHO_MSG} "*** Create and Edit the config files in:"
	@${ECHO_MSG} "***      ${PREFIX}/etc/dnews"
.if defined(DNEWSWEB)
	@${ECHO_MSG} "***      and ${PREFIX}/www/cgi-bin/dnewsweb.ini !"
.endif

.include <bsd.port.mk>
