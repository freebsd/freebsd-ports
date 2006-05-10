# New ports collection makefile for:	ssmtp
# Date created:		9 Jan 2001
# Whom:			Tomasz Paszkowski <ns88@k.pl>
#
# $FreeBSD$
#

PORTNAME=	ssmtp
PORTVERSION=	2.61
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--enable-ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAILERCONF=	/etc/mail/mailer.conf
TRUE=		/usr/bin/true

MAN8=		ssmtp.8

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

post-install:
	@${ECHO_MSG} --------------------------------------------------
	@${ECHO_MSG}
	@${ECHO_MSG} "To replace sendmail with ssmtp type make replace"
	@${ECHO_MSG}
	@${ECHO_MSG} --------------------------------------------------
	@${SED} 's#%%PREFIX%%#${PREFIX}#' < ${PKGMESSAGE}

.include <bsd.port.mk>
