# New ports collection makefile for:		cyrus-imapd
# Date created:					Jan 4th 2001
# Whom:						ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus-imapd
PORTVERSION= 	2.0.16
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20020118.diff.gz

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
MAN8=		arbitron.8 collectnews.8 ctl_deliver.8 ctl_mboxlist.8 \
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
		install-testing install-upgrade install mailing-list man \
		notes os overview questions readme sieve-protocol sieve specs

post-patch:
		@${SED} -e "s|/etc/|${PREFIX}/etc/|" ${WRKSRC}/tools/mkimap \
			> ${WRKSRC}/tools/mkimap.new
		@${MV} ${WRKSRC}/tools/mkimap.new ${WRKSRC}/tools/mkimap

pre-install:
		@ ${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8
		@${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
		@ ${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/cyrus/man
		${MKDIR} ${PREFIX}/share/doc/cyrus/text
.for file in ${HTDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${file}.html \
			${PREFIX}/share/doc/cyrus
		@${ECHO} share/doc/cyrus/${file}.html >>${TMPPLIST}
.endfor
.for file in ${MAN1} ${MAN3} ${MAN5} ${MAN8}
		ofile=`echo ${file} | sed s/cyrquota/quota/`; \
		if [ -f ${WRKSRC}/doc/man/$${ofile}.html ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/man/$${ofile}.html \
			${PREFIX}/share/doc/cyrus/man/$${ofile}.html; \
		${ECHO} share/doc/cyrus/man/$${ofile}.html >>${TMPPLIST}; \
		fi
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
		@${ECHO} "@dirrm share/doc/cyrus/man" >>${TMPPLIST}
		@${ECHO} "@dirrm share/doc/cyrus" >>${TMPPLIST}
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

.include <bsd.port.mk>
