# New ports collection makefile for:	ssmtp
# Date created:		9 Jan 2001
# Whom:			Tomasz Paszkowski <ns88@k.pl>
#
# $FreeBSD$
#

PORTNAME=	ssmtp
PORTVERSION=	2.60.4
PORTREVISION=	2
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.[0-9]+$//}

USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--enable-ssl --enable-inet6
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAILERCONF=	/etc/mail/mailer.conf
TRUE=		/usr/bin/true

MAN8=		ssmtp.8

.if defined(WITH_USERPREFS)
CFLAGS+=	-DUSERPREFS
.else
pre-everything::
	@${ECHO_CMD} 'If you want to let your users set their own revalias address,'
	@${ECHO_CMD} 'please define WITH_USERPREFS (they just have to put their mail'
	@${ECHO_CMD} 'address in ~/.ssmtprc).'
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
