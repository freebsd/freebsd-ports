# New ports collection makefile for:		cyrus
# Version required:				1.5.2
# Date created:					May 4th 1997
# Whom:						jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.6 1998/02/24 21:43:06 jseger Exp $
#

DISTNAME=	cyrus-imapd-v1.5.2
PKGNAME=	cyrus-1.5.2
CATEGORIES=	mail tcl81
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	jfitz@FreeBSD.ORG

LIB_DEPENDS=	tcl81\\.1\\.:${PORTSDIR}/lang/tcl81
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-group=cyrus \
		--with-tcl=${PREFIX} \
		--with-login=unix_pwcheck \
		--with-auth=unix

MAN1=		cyradm.1
MAN3=		imclient.3
MAN5=		imapd.conf.5
MAN8=		arbitron.8 collectnews.8 cyrquota.8 deliver.8 imapd.8 \
		pop3d.8 reconstruct.8 rmnews.8 syncnews.8

post-configure:
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl -pi -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/imap/config.c ${WRKSRC}/imap/krbck.c

pre-install:
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser
		@ ${CP} ${WRKSRC}/man/quota.8 ${WRKSRC}/man/cyrquota.8

post-install:
		@ ${MV} ${PREFIX}/cyrus/bin/quota ${PREFIX}/cyrus/bin/cyrquota
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/cyrus/html
.for file in acl-extension bugs changes copyrights install overview quota-extension server-design
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/cyrus
.endfor
		${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/cyrus/html
.endif
		${INSTALL_DATA} ${FILESDIR}/imapd.conf ${PREFIX}/etc
		${MKDIR} -m 750 /var/spool/imap
		/usr/sbin/chown cyrus.cyrus /var/spool/imap
		${MKDIR} -m 700 /var/pwcheck
		/usr/sbin/chown cyrus.cyrus /var/pwcheck
		${MKDIR} -m 750 ${PREFIX}/etc/imap
		/usr/sbin/chown cyrus.cyrus ${PREFIX}/etc/imap
		/usr/bin/touch ${PREFIX}/etc/imap/mailboxes
		/bin/chmod 640 ${PREFIX}/etc/imap/mailboxes
		${MKDIR} -m 750 \
			${PREFIX}/etc/imap/user \
			${PREFIX}/etc/imap/quota \
			${PREFIX}/etc/imap/proc \
			${PREFIX}/etc/imap/log \
			${PREFIX}/etc/imap/msg
		/usr/sbin/chown cyrus.cyrus ${PREFIX}/etc/imap/*
		echo "Installing ${PREFIX}/etc/rc.d/cyrus.sh startup file."; \
		cat ${FILESDIR}/cyrus.sh.pt1 > ${PREFIX}/etc/rc.d/cyrus.sh
		echo PREFIX=${PREFIX} >> ${PREFIX}/etc/rc.d/cyrus.sh
		cat ${FILESDIR}/cyrus.sh.pt2 >> ${PREFIX}/etc/rc.d/cyrus.sh
		/bin/chmod 751 ${PREFIX}/etc/rc.d/cyrus.sh

.include <bsd.port.mk>
