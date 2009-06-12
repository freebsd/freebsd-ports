# New ports collection makefile for:    sudo
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sudo
PORTVERSION=	1.6.9.20
CATEGORIES=	security
MASTER_SITES=	http://www.sudo.ws/sudo/dist/ \
		ftp://obsd.isc.org/pub/sudo/ \
		ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
		ftp://boulder.tele.dk/pub/sudo/ \
		ftp://core.ring.gr.jp/pub/misc/sudo/ \
		ftp://ftp.wiretapped.net/pub/security/host-security/sudo/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tmclaugh/sudo
DISTNAME=	${PORTNAME}-1.6.9p20

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
		SHELL_SETS_HOME "Set HOME env to target user in shell mode" off \
		DISABLE_ROOT_SUDO	"Disable root sudo" off \
		DISABLE_AUTH "Disable authentication" off \
		NOARGS_SHELL "Enable no arguments shell" off

.include <bsd.port.pre.mk>

# SUDO_SECURE_PATH is a PATH string that will override the user's PATH.
# ex: make SUDO_SECURE_PATH="/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
.if defined(SUDO_SECURE_PATH)
CONFIGURE_ARGS+=--with-secure-path="${SUDO_SECURE_PATH}"
.endif

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

.if defined(WITH_DISABLE_ROOT_SUDO)
CONFIGURE_ARGS+=--disable-root-sudo
.endif

.if defined(WITH_DISABLE_AUTH)
CONFIGURE_ARGS+=--disable-authentication
.endif

.if defined(WITH_NOARGS_SHELL)
CONFIGURE_ARGS+=--enable-noargs-shell
.endif

MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8
MLINKS=		sudo.8 sudoedit.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/etc/sudoers.default
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/sudo.default

	if [ ! -e ${PREFIX}/etc/pam.d/sudo ]; then \
		${CP} -p ${PREFIX}/etc/pam.d/sudo.default \
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
	${INSTALL_DATA} ${WRKSRC}/schema.OpenLDAP ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sudoers2ldif ${DOCSDIR}
.endif
.endif

.include <bsd.port.post.mk>
