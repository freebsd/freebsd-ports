# New ports collection makefile for:    sudo
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sudo
PORTVERSION=	1.6.9.3
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
DISTNAME=	${PORTNAME}-1.6.9p3

MAINTAINER=	tmclaugh@FreeBSD.org
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
		INSULTS "With all insults" off \
		SHELL_SETS_HOME "Set HOME env to target user in shell mode" off

.include <bsd.port.pre.mk>

.if defined(WITH_INSULTS)
CONFIGURE_ARGS+=--with-insults
CONFIGURE_ARGS+=--with-all-insults
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=yes
CONFIGURE_ARGS+=--with-ldap=${PREFIX}
CONFIGURE_ARGS+=--with-ldap-conf-file=${PREFIX}/etc/ldap.conf
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB=	LDAP="@comment "
.endif

.if defined(WITH_SHELL_SETS_HOME)
CONFIGURE_ARGS+=--enable-shell-sets-home
.endif

MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8
MLINKS=		sudo.8 sudoedit.8

post-install:
	${RM} ${PREFIX}/libexec/sudo_noexec.la
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/etc/sudoers.default
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/sudo.default

	if [ ! -e ${PREFIX}/etc/pam.d/sudo ]; then \
		cp -p ${PREFIX}/etc/pam.d/sudo.default \
		${PREFIX}/etc/pam.d/sudo ;\
	fi

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TROUBLESHOOTING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers ${DOCSDIR}
.if defined(WITH_LDAP)
	${INSTALL_DATA} ${WRKSRC}/README.LDAP ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sudoers2ldif ${DOCSDIR}
.endif
.endif

.include <bsd.port.post.mk>
