# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION= 	2.1.11
#PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20021205.diff.gz

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2 \
		db3.3:${PORTSDIR}/databases/db3
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend \
		${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2

USE_PERL5=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-group=cyrus \
		--with-sasl=${LOCALBASE} \
		--with-dbdir=${LOCALBASE} \
		--with-auth=unix \
		--with-com_err

.if defined(WITH_SKIPLIST_MBOX)
CONFIGURE_ARGS+=--with-mboxlist-db=skiplist
.endif

.if defined(WITH_MURDER)
CONFIGURE_ARGS+=--enable-murder
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=	MURDER=""
.else
PLIST_SUB+=	MURDER="@comment "
.endif

.if defined(WITH_SNMP)
# It seems not compilable due to lack of auto_nlist_value() in libucdagent.
LIB_DEPENDS+=	netsnmp.5:${PORTSDIR}/net/net-snmp
#CONFIGURE_ENV=	LIBS=-lkvm
.else
CONFIGURE_ARGS+=--with-ucdsnmp=no
.endif

MAN1=		cyradm.1 imtest.1 installsieve.1 lmtptest.1 mupdatetest.1 \
		pop3test.1 sieveshell.1 sivtest.1 smtptest.1
MAN3=		imclient.3
MAN5=		cyrus.conf.5 imapd.conf.5 krb.equiv.5
MAN8=		arbitron.8 chk_cyrus.8 collectnews.8 ctl_cyrusdb.8 \
		ctl_deliver.8 ctl_mboxlist.8 cvt_cyrusdb.8 cyrquota.8 \
		deliver.8 fud.8 idled.8 imapd.8 ipurge.8 lmtpd.8 master.8 \
		mbpath.8 notifyd.8 pop3d.8 reconstruct.8 rmnews.8 \
		squatter.8 syncnews.8 timsieved.8 tls_prune.8

DOCS=		altnamespace anoncvs bugs changes faq feedback index \
		install install-admin-mb install-auth install-compile \
		install-configure install-murder install-perf \
		install-prereq install-sieve install-snmpmon install-testing \
		install-upgrade mailing-list man notes os overview questions \
		readme sieve sieve-protocol specs

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif
.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser
.endif

post-patch:
		@${SED} -e "s|/etc/|${PREFIX}/etc/|" ${WRKSRC}/tools/mkimap \
			> ${WRKSRC}/tools/mkimap.new
		@${MV} ${WRKSRC}/tools/mkimap.new ${WRKSRC}/tools/mkimap
		@${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8
.if ${PERL_LEVEL} < 500600
		@${SED} -e "s|exec perl -x|exec perl -I${LOCALBASE}/lib/perl5/site_perl/${PERL_VER} -x|" \
			${WRKSRC}/perl/sieve/scripts/sieveshell.pl \
			> ${WRKSRC}/perl/sieve/scripts/sieveshell.pl.new
		@${MV} ${WRKSRC}/perl/sieve/scripts/sieveshell.pl.new \
			${WRKSRC}/perl/sieve/scripts/sieveshell.pl
.endif

post-install:
		@${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/cyrus-imapd2/man
		${MKDIR} ${PREFIX}/share/doc/cyrus-imapd2/text
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${file}.html \
			${PREFIX}/share/doc/cyrus-imapd2
		@${ECHO} share/doc/cyrus-imapd2/${file}.html >>${TMPPLIST}
.endfor
.for file in ${MAN1} ${MAN3} ${MAN5} ${MAN8}
		ofile=`echo ${file} | sed s/cyrquota/quota/`; \
		if [ -f ${WRKSRC}/doc/man/$${ofile}.html ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/man/$${ofile}.html \
			${PREFIX}/share/doc/cyrus-imapd2/man/$${ofile}.html; \
		${ECHO} share/doc/cyrus-imapd2/man/$${ofile}.html \
			>>${TMPPLIST}; \
		fi
.endfor
		${INSTALL_DATA} ${WRKSRC}/doc/cyrusv2.mc \
			${PREFIX}/share/doc/cyrus-imapd2
		@${ECHO} share/doc/cyrus-imapd2/cyrusv2.mc >>${TMPPLIST}
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/text/${file} \
			${PREFIX}/share/doc/cyrus-imapd2/text
		@${ECHO} share/doc/cyrus-imapd2/text/${file} >>${TMPPLIST}
.endfor
		@${ECHO} "@dirrm share/doc/cyrus-imapd2/text" >>${TMPPLIST}
		@${ECHO} "@dirrm share/doc/cyrus-imapd2/man" >>${TMPPLIST}
		@${ECHO} "@dirrm share/doc/cyrus-imapd2" >>${TMPPLIST}
.endif
		${INSTALL_SCRIPT} ${FILESDIR}/imapd.sh \
			${PREFIX}/etc/rc.d/imapd.sh.sample
		${INSTALL_DATA} ${FILESDIR}/imapd.conf \
			${PREFIX}/etc/imapd.conf.dist
		${INSTALL_DATA} ${WRKSRC}/master/conf/normal.conf \
			${PREFIX}/etc/cyrus.conf.dist
		${INSTALL_SCRIPT} ${WRKSRC}/tools/mkimap \
			${PREFIX}/cyrus/bin/mkimap
		@PKG_PREFIX=${PREFIX} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
