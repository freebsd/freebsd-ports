# New ports collection makefile for:		cyrus
# Version required:				1.5.14
# Date created:					May 4th 1997
# Whom:						jfitz@FreeBSD.ORG
#
# $Id: Makefile,v 1.11 1998/11/04 01:34:59 jdp Exp $
#

DISTNAME=	cyrus-imapd-v1.5.14
PKGNAME=	cyrus-1.5.14
CATEGORIES=	mail tcl80
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.promo.de/pub/people/stefan/FreeBSD/cyrus-mail/

MAINTAINER=	stb@FreeBSD.ORG

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cyrus-prefix=${PREFIX}/cyrus \
		--with-cyrus-group=cyrus \
		--with-login=unix_pwcheck \
		--with-tclsh=${PREFIX}/bin/tclsh8.0 \
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
		${INSTALL} -d -m 750 -o cyrus -g cyrus /var/spool/imap \
			${PREFIX}/etc/imap \
			${PREFIX}/etc/imap/user \
			${PREFIX}/etc/imap/quota \
			${PREFIX}/etc/imap/proc \
			${PREFIX}/etc/imap/log \
			${PREFIX}/etc/imap/msg
		${INSTALL} -d -m 700 -o cyrus -g cyrus /var/pwcheck
		${TOUCH} ${PREFIX}/etc/imap/mailboxes
		chmod 640 ${PREFIX}/etc/imap/mailboxes
		@sed -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/cyrus.sh \
			>${PREFIX}/etc/rc.d/cyrus.sh
		@chmod 0755 ${PREFIX}/etc/rc.d/cyrus.sh

.include <bsd.port.mk>
