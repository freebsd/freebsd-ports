# New ports collection makefile for:		cyrus
# Date created:					May 4th 1997
# Whom:						jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cyrus
PORTVERSION= 	1.6.22
CATEGORIES=	mail tcl82
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://people.FreeBSD.org/~stb/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/
DISTNAME=	${PORTNAME}-imapd-${PORTVERSION}

MAINTAINER=	stb@FreeBSD.org

Y2K=		http://andrew2.andrew.cmu.edu/cyrus/imapd/y2k.html

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend \
		pwcheck:${PORTSDIR}/security/cyrus-sasl

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-group=cyrus \
		--with-sasldir=/usr/local \
		--with-tclsh=${PREFIX}/bin/tclsh8.2 \
		--with-auth=unix \
		--with-com-err

MAN1=		cyradm.1
MAN3=		imclient.3
MAN5=		imapd.conf.5
MAN8=		arbitron.8 collectnews.8 cyrquota.8 deliver.8 imapd.8 \
		pop3d.8 reconstruct.8 rmnews.8 syncnews.8

post-configure:
		@ ${SETENV} ${MAKE_ENV} perl -pi -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/imap/config.c ${WRKSRC}/imap/krbck.c

pre-install:
		@ ${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8
		@${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

DOCS=	README acl-extension anoncvs bugs changes copyrights install \
	mailing-list overview quota-extension server-design
HTDOCS=	anoncvs bugs changes index install mailing-list overview \
	questions readme sieve-protocol sieve
post-install:
		@ ${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/cyrus/html
.for file in ${DOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/${file} \
			${PREFIX}/share/doc/cyrus
		@${ECHO} share/doc/cyrus/${file} >>${TMPPLIST}
.endfor
.for file in ${HTDOCS}
		${INSTALL_DATA} ${WRKSRC}/doc/html/${file}.html \
			${PREFIX}/share/doc/cyrus/html
		@${ECHO} share/doc/cyrus/html/${file}.html >>${TMPPLIST}
.endfor
		@${ECHO} "@dirrm share/doc/cyrus/html" >>${TMPPLIST}
		@${ECHO} "@dirrm share/doc/cyrus" >>${TMPPLIST}
.endif
		${INSTALL_DATA} ${FILESDIR}/imapd.conf \
			${PREFIX}/etc/imapd.conf.dist
		${INSTALL_DATA} ${FILESDIR}/inetd.conf.cyrus \
			${PREFIX}/etc/
		${INSTALL} -d -m 750 -o cyrus -g cyrus \
			/var/spool/imap \
			${PREFIX}/etc/imap \
			${PREFIX}/etc/imap/user \
			${PREFIX}/etc/imap/quota \
			${PREFIX}/etc/imap/proc \
			${PREFIX}/etc/imap/log \
			${PREFIX}/etc/imap/msg
		${INSTALL} -d -m 700 -o cyrus -g cyrus /var/pwcheck
		${TOUCH} ${PREFIX}/etc/imap/mailboxes
		${CHMOD} 640 ${PREFIX}/etc/imap/mailboxes
		chown cyrus:cyrus ${PREFIX}/etc/imap/mailboxes
		@${ECHO} "@exec mkdir %D/etc/imap" >>${TMPPLIST}
.for dir in user quota proc log msg
		@${ECHO} "@exec mkdir %D/etc/imap/${dir}" >>${TMPPLIST}
		@${ECHO} "@dirrm etc/imap/${dir}" >>${TMPPLIST}
.endfor
		@${ECHO} "@exec cp /dev/null %D/etc/imap/mailboxes" >>${TMPPLIST}
		@${ECHO} "@exec chown -R cyrus:cyrus %D/etc/imap" >>${TMPPLIST}
		@${ECHO} "@exec chmod -R g-w,o= %D/etc/imap" >>${TMPPLIST}
		@${ECHO} "@mode u=rwx,go=" >>${TMPPLIST}
		@${ECHO} "@exec mkdir /var/pwcheck" >>${TMPPLIST}
		@${ECHO} "@exec chown cyrus:cyrus /var/pwcheck" >>${TMPPLIST}
		@${ECHO} "@exec chmod go= /var/pwcheck" >>${TMPPLIST}
		@${ECHO} "@exec mkdir /var/spool/imap" >>${TMPPLIST}
		@${ECHO} "@exec chown cyrus:cyrus /var/spool/imap" >>${TMPPLIST}
		@${ECHO} "@exec chmod g-w,o= /var/spool/imap" >>${TMPPLIST}
		@${ECHO} "@cwd /var" >>${TMPPLIST}
		@${ECHO} "@dirrm pwcheck" >>${TMPPLIST}
		@${ECHO} "@dirrm spool/imap" >>${TMPPLIST}
		@${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/cyrus.sh \
			>${PREFIX}/etc/rc.d/cyrus.sh
		@${CHMOD} 0755 ${PREFIX}/etc/rc.d/cyrus.sh
		@PKG_PREFIX=${PREFIX} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
