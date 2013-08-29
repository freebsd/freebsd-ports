# Created by: Tomasz Paszkowski <ns88@k.pl>
# $FreeBSD$

PORTNAME=	ssmtp
PORTVERSION=	2.64
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	aragon@phat.za.net
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
GROUPS=		ssmtp
SHAREGRP=	ssmtp
BINMODE=	2555
SHAREMODE=	640
BINGRP=		ssmtp

SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ARGS=	--enable-ssl --enable-md5auth
MAKE_ENV+=	TARGET_ARCH=
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAILERCONF=	/etc/mail/mailer.conf

MAN8=		ssmtp.8
MAN5=		ssmtp.conf.5

OPTIONS_DEFINE=	LOGFILE IPV6 USERPREFS XORIGIP
LOGFILE_DESC=	log file
USERPREFS_DESC=	user defined revaliases
XORIGIP_DESC=	Add X-Originating-IP header

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOGFILE}
CONFIGURE_ARGS+=	--enable-logfile
.endif

.if ${PORT_OPTIONS:MXORIGIP}
EXTRA_PATCHES=	${FILESDIR}/remote-addr.patch
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if ${PORT_OPTIONS:MUSERPREFS}
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
	@${ECHO_CMD} "hoststat	/usr/bin/true" >> ${MAILERCONF}
	@${ECHO_CMD} "purgestat	/usr/bin/true" >> ${MAILERCONF}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ssmtp ${PREFIX}/sbin/ssmtp
	@${MKDIR} ${PREFIX}/etc/ssmtp
	@${CHMOD} 750 ${PREFIX}/etc/ssmtp
	@${CHGRP} ${SHAREGRP} ${PREFIX}/etc/ssmtp
	@${INSTALL_DATA} ${WRKSRC}/revaliases ${PREFIX}/etc/ssmtp/revaliases.sample
	@${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${PREFIX}/etc/ssmtp/ssmtp.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/ssmtp.8 ${MANPREFIX}/man/man8/ssmtp.8
	@${INSTALL_MAN} ${WRKSRC}/ssmtp.conf.5 ${MANPREFIX}/man/man5/ssmtp.conf.5
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
