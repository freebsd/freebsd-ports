# New ports collection makefile for:    sudo
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sudo
PORTVERSION=	1.6.8.12
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.sudo.ws/sudo/dist/ \
		http://probsd.org/sudoftp/ \
		http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/sudo/ \
		http://mirrors.theonlinerecordstore.com/sudo/ \
		http://core.ring.gr.jp/archives/misc/sudo/ \
		http://www.ring.gr.jp/archives/misc/sudo/ \
		http://sudo.tsuren.net/dist/ \
		http://pluto.cdpa.nsysu.edu.tw/sudo/ \
		ftp://ftp.cs.colorado.edu/pub/sysadmin/sudo/ \
		ftp://ftp.stikman.com/pub/sudo/
DISTNAME=	${PORTNAME}-1.6.8p12

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow others to run commands as root

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--disable-log-wrap \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-logincap \
		--with-long-otp-prompt \
		--with-pam

OPTIONS=	LDAP	"With LDAP support" off \
		OPIE	"With OPIE support" off \
		SHELL_SETS_HOME "Set HOME env to target user in shell mode" off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
USE_OPENLDAP=yes
CONFIGURE_ARGS+=--with-ldap=${PREFIX}
CONFIGURE_ARGS+=--with-ldap-conf-file=${PREFIX}/etc/ldap.conf
.endif

.if defined(WITH_OPIE) || ${OSVERSION} > 500021
CONFIGURE_ARGS+=--with-opie
.else
CONFIGURE_ARGS+=--with-skey
.endif

.if defined(WITH_SHELL_SETS_HOME)
CONFIGURE_ARGS+=--enable-shell-sets-home
.endif

MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8
MLINKS=		sudo.8 sudoedit.8

post-patch:
	@${REINPLACE_CMD} -e 's|^|#|g' ${WRKSRC}/sample.sudoers

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${PREFIX}/etc/sudoers.sample
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/etc/sudoers.default
	${RM} ${PREFIX}/libexec/sudo_noexec.la
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/sudo

.include <bsd.port.post.mk>
