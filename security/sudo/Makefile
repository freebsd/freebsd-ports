# New ports collection makefile for:    sudo
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	sudo
PORTVERSION=	1.7.4.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.sudo.ws/sudo/dist/ \
		ftp://obsd.isc.org/pub/sudo/ \
		ftp://ftp.uwsg.indiana.edu/pub/security/sudo/ \
		ftp://boulder.tele.dk/pub/sudo/ \
		ftp://core.ring.gr.jp/pub/misc/sudo/ \
		ftp://ftp.wiretapped.net/pub/security/host-security/sudo/
DISTNAME=	${PORTNAME}-1.7.4p2

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Allow others to run commands as root

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-ignore-dot \
		--with-tty-tickets \
		--with-env-editor \
		--with-logincap \
		--with-long-otp-prompt \
		--with-pam

OPTIONS=	LDAP "With LDAP support" off \
		INSULTS "With all insults" off \
		SHELL_SETS_HOME "Set HOME env to target user in shell mode" off \
		DISABLE_ROOT_SUDO "Disable root sudo" off \
		DISABLE_AUTH "Disable authentication" off \
		NOARGS_SHELL "Enable no arguments shell" off

LOGFAC?=	local2
CONFIGURE_ARGS+=--with-logfac=${LOGFAC}

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
SUDO_LDAP_CONF?=ldap.conf
CONFIGURE_ARGS+=--with-ldap-conf-file=${PREFIX}/etc/${SUDO_LDAP_CONF}
PLIST_SUB+=	LDAP=""
MAN5+=	sudoers.ldap.5
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

MAN5+=		sudoers.5
MAN8=		sudo.8 visudo.8 sudoreplay.8
MLINKS=		sudo.8 sudoedit.8

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/$$(DESTDIR)$$(sudoersdir) $$(DESTDIR)$$(docdir)/$$(DESTDIR)$$(sudoersdir)/' \
		${WRKSRC}/Makefile.in

	@${REINPLACE_CMD} -e '/for f in ChangeLog/d' ${WRKSRC}/Makefile.in
.endif

post-install:
	if [ ! -f ${PREFIX}/etc/sudoers ]; then \
		${CP} -p ${PREFIX}/etc/sudoers.sample ${PREFIX}/etc/sudoers; \
	fi

.include <bsd.port.post.mk>
