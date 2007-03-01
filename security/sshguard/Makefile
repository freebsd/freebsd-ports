# New ports collection makefile for:	sshguard
# Date created:		2007-02-22
# Whom:			Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	sshguard
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mij@bitchx.it
COMMENT=	Protect networked hosts from brute force attacks against ssh

PLIST_FILES=	sbin/sshguard

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
HAS_CONFIGURE=	yes

OPTIONS=	PF	"Use PF as firewall backend"	off \
		IPFW	"Use IPFW as firewall backend"	off

.include <bsd.port.pre.mk>

.if ! ( (defined(WITH_PF) && !defined(WITH_IPFW)) || !defined(WITH_PF))
# some error occurred. Configure will handle this.
.endif

.if defined(WITH_PF)
# compile with PF support
CONFIGURE_ARGS+=	--with-firewall=pf
.elif defined(WITH_IPFW)
# compile with IPFW support
CONFIGURE_ARGS+=	--with-firewall=ipfw
.endif

post-install:
	# spare pkg-message
	${ECHO_MSG} "		Sshguard installed successfully."
	${ECHO_MSG} "Make it active by putting in /etc/syslog.conf something like:"
	${ECHO_MSG} "	auth.info;authpriv.info     |exec ${PREFIX}/sbin/sshguard"
	${ECHO_MSG} "Otherwise, run sshguard standalone with (as root):"
	${ECHO_MSG} "	tail -n 0 -f /var/log/auth.log | ${PREFIX}/sbin/sshguard"

.include <bsd.port.post.mk>
