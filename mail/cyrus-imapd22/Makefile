# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION= 	2.0.12
PORTREVISION=	3
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20010222.diff.gz

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	sasl.8:${PORTSDIR}/security/cyrus-sasl \
		db3.2:${PORTSDIR}/databases/db3
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend \
		${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-group=cyrus \
		--with-sasl=${LOCALBASE} \
		--with-dbdir=${LOCALBASE} \
		--with-auth=unix \
		--with-com_err

.if defined(WITH_SNMP)
# It seems not compilable due to lack of auto_nlist_value() in libucdagent.
CONFIGURE_ENV=	LIBS=-lkvm
.else
CONFIGURE_ARGS+=--with-ucdsnmp=no
.endif

MAN1=		cyradm.1 imtest.1 installsieve.1
MAN3=		imclient.3
MAN5=		cyrus.conf.5 imapd.conf.5 krb.equiv.5
MAN8=		arbitron.8 ctl_deliver.8 ctl_mboxlist.8 collectnews.8 \
		cyrquota.8 deliver.8 fud.8 idled.8 imapd.8 ipurge.8 \
		lmtpd.8 master.8 mbpath.8 pop3d.8 reconstruct.8 rmnews.8 \
		syncnews.8 timsieved.8

DOCS=		HEY-YOU-WITH-THE-EDITOR README acl-extension anoncvs bugs \
		changes copyrights feedback index install install-admin-mb \
		install-compile install-configure install-murder install-perf \
		install-prereq install-sieve install-snmpmon install-testing \
		install-upgrade mailing-list notes os overview questions \
		quota-extension readme server-design sieve sieve-protocol
HTDOCS=		anoncvs bugs changes faq feedback index install-admin-mb \
		install-auth install-compile install-configure install-murder \
		install-perf install-prereq install-sieve install-snmpmon \
		install-testing install-upgrade install mailing-list notes \
		os overview questions readme sieve-protocol sieve

pre-install:
		@ ${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8
		@${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
		@ ${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/cyrus/text
.for file in ${HTDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${file}.html \
			${PREFIX}/share/doc/cyrus
		@${ECHO} share/doc/cyrus/${file}.html >>${TMPPLIST}
.endfor
		${INSTALL_DATA} ${WRKSRC}/doc/cyrusv2.mc \
			${PREFIX}/share/doc/cyrus
		@${ECHO} share/doc/cyrus/cyrusv2.mc >>${TMPPLIST}
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/text/${file} \
			${PREFIX}/share/doc/cyrus/text
		@${ECHO} share/doc/cyrus/text/${file} >>${TMPPLIST}
.endfor
		@${ECHO} "@dirrm share/doc/cyrus/text" >>${TMPPLIST}
		@${ECHO} "@dirrm share/doc/cyrus" >>${TMPPLIST}
.endif
		${INSTALL_SCRIPT} ${FILESDIR}/imapd.sh \
			${PREFIX}/etc/rc.d/imapd.sh.sample
		${INSTALL_DATA} ${FILESDIR}/imapd.conf \
			${PREFIX}/etc/imapd.conf.dist
		${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
			${PREFIX}/etc/cyrus.conf.dist
		${WRKSRC}/tools/mkimap ${FILESDIR}/imapd.conf
		${CHOWN} -R cyrus:cyrus /var/imap
		${CHOWN} -R cyrus:cyrus /var/spool/imap
		@${ECHO} "@cwd /var" >>${TMPPLIST}
		@${ECHO} "@exec ${MKDIR} imap" >>${TMPPLIST}
.for dir in user socket sieve quota proc msg log deliverdb/db deliverdb db
		@${ECHO} "@exec ${MKDIR} imap/${dir}" >>${TMPPLIST}
		@${ECHO} "@dirrm imap/${dir}" >>${TMPPLIST}
.endfor
		@${ECHO} "@dirrm imap" >>${TMPPLIST}
		@${ECHO} "@exec ${CHOWN} -R cyrus:cyrus imap" >>${TMPPLIST}
		@${ECHO} "@exec ${CHMOD} -R g-w,o= imap" >>${TMPPLIST}
		@${ECHO} "@mode u=rwx,go=" >>${TMPPLIST}
		@${ECHO} "@exec ${MKDIR} spool/imap" >>${TMPPLIST}
		@${ECHO} "@exec ${CHOWN} cyrus:cyrus spool/imap" >>${TMPPLIST}
		@${ECHO} "@exec ${CHMOD} g-w,o= spool/imap" >>${TMPPLIST}
		@${ECHO} "@dirrm spool/imap/stage." >>${TMPPLIST}
		@${ECHO} "@dirrm spool/imap" >>${TMPPLIST}
		@PKG_PREFIX=${PREFIX} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
