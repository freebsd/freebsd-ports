# New ports collection makefile for:	ssmtp
# Date created:		9 Jan 2001
# Whom:			Tomasz Paszkowski <ns88@k.pl>
#
# $FreeBSD$
#

PORTNAME=	ssmtp
PORTVERSION=	2.62.3
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_2.62.orig

MAINTAINER=	aragon@phat.za.net
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

SSMTP_GROUP=	ssmtp
SSMTP_GID=	916

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	SSMTP_GROUP="${SSMTP_GROUP}" \
		SSMTP_GID="${SSMTP_GID}" \
		ETCDIR="${ETCDIR}" \
		CHOWN="${CHOWN}" CHMOD="${CHMOD}" PW="${PW}"

CONFIGURE_ARGS=	--enable-ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAILERCONF=	/etc/mail/mailer.conf

MAN8=		ssmtp.8

.include <bsd.port.pre.mk>

.if defined(WITH_LOGFILE)
CONFIGURE_ARGS+=	--enable-logfile
.endif

.if defined(WITH_MD5AUTH)
CONFIGURE_ARGS+=	--enable-md5auth
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if !defined(WITHOUT_USERPREFS)
CFLAGS+=	-DUSERPREFS
pre-everything::
	@${ECHO_CMD} "If you don't want to let your users set their own revalias address"
	@${ECHO_CMD} "(in ~/.ssmtprc), please define WITHOUT_USERPREFS."
.endif

post-configure:
	@${REINPLACE_CMD} -e "s,/etc/ssl/certs/ssmtp.pem,${PREFIX}/etc/ssmtp/ssmtp.pem,g" \
		${WRKSRC}/ssmtp.c ${WRKSRC}/ssmtp.conf
	@${REINPLACE_CMD} -e "s, /etc, ${PREFIX}/etc,g" ${WRKSRC}/ssmtp.8

replace:
	@${REINPLACE_CMD} -e 's,^[^#],#&,g' ${MAILERCONF}
	@${ECHO_CMD} "sendmail	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "send-mail	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "mailq		${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "newaliases	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "hoststat	${TRUE}" >> ${MAILERCONF}
	@${ECHO_CMD} "purgestat	${TRUE}" >> ${MAILERCONF}

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
