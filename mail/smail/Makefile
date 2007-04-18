# New ports collection makefile for:	smail
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	smail
PORTVERSION=	3.2.0.121
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.planix.com/pub/Smail/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/mail/smail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program used for receiving and delivering mail

BUILD_DEPENDS=	${LOCALBASE}/lib/libident.a:${PORTSDIR}/security/libident
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS=	bsmtp-1.* courier-0.* postfix-1.* postfix-2.* sendmail-8.* sendmail-*-8.* zmailer-2.*

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		pathto.1 uuwho.1 uupath.1
MAN5=		smailconf.5 smail.5 smaildrct.5 smailmeth.5 smailqual.5 \
		smailrtrs.5 smailrtry.5 smailtrns.5 aliases.5
MAN8=		pathalias.8 mkdbm.8 mkline.8 mksort.8 mkaliases.8 smail.8 \
		mkpath.8 pathmerge.8 checkerr.8 getmap.8 mkhpath.8 savelog.8 \
		mkuuwho.8 mailq.8 sendmail.8 runq.8 rmail.8 rsmtp.8 smtpd.8 \
		newaliases.8 smailbug.8 unfreezemail.8 bouncemail.8 logsumm.8
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lident -lwrap -lpcre

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus
CYRUS_DELIVER_PATH?=	${LOCALBASE}/cyrus/bin/deliver

OPTIONS=	CYRUS22 "Use mail/cyrus-imapd22 as local transport" off \
		CYRUS23 "Use mail/cyrus-imapd23 as local transport" off \
		REPLACE_CONF "Replace /etc/mail/mailer.conf" off

.include <bsd.port.pre.mk>

.if defined(WITH_CYRUS22) && defined(WITH_CYRUS23)
IGNORE=		WITH_CYRUS22 and WITH_CYRUS23 are mutually exclusive. Please run make options again
.endif

.if defined(WITH_CYRUS22)
CYRUS_PORT=	${PORTSDIR}/mail/cyrus-imapd22
.else
CYRUS_PORT=	${PORTSDIR}/mail/cyrus-imapd23
.endif

.if defined(WITH_CYRUS22) || defined(WITH_CYRUS23)
RUN_DEPENDS+=	cyrus/bin/deliver:${CYRUS_PORT}
CYRUS_IMAPD=	USE_CYRUS_IMAPD
PLIST_SUB+=	CYRUS_DELIVER=""
.else
PLIST_SUB+=	CYRUS_DELIVER="@comment "
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
ARCH_TYPE=64bit
.else
ARCH_TYPE=32bit
.endif

do-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%MANPREFIX%%|${MANPREFIX}|g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		-e 's|%%CPPFLAGS%%|${CPPFLAGS}|g' \
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g' \
		-e 's|%%LIBS%%|${LIBS}|g' \
		-e 's|%%ARCH_TYPE%%|${ARCH_TYPE}|g' \
		-e 's|%%CYRUS_IMAPD%%|${CYRUS_IMAPD}|g' \
		${FILESDIR}/freebsd5.in > ${WRKSRC}/conf/os/freebsd5
	@${ECHO_CMD} OS_TYPE=freebsd5 > ${WRKSRC}/conf/EDITME
	@${ECHO_CMD} STRIP=yes >> ${WRKSRC}/conf/EDITME
	@${ECHO_CMD} CYRUS_USER="${CYRUS_USER}" >> ${WRKSRC}/conf/EDITME
	@${ECHO_CMD} CYRUS_GROUP="${CYRUS_GROUP}" >> ${WRKSRC}/conf/EDITME
	@${ECHO_CMD} CYRUS_DELIVER_PATH="${CYRUS_DELIVER_PATH}" >> ${WRKSRC}/conf/EDITME
	@${LN} -sf ${WRKSRC}/conf/Make.local-BSD ${WRKSRC}/conf/Make.local
	@${REINPLACE_CMD} -e 's|defs install|defs|g' \
		${WRKSRC}/man/Makefile
	@${ECHO_CMD} >> ${WRKSRC}/man/Makefile
	@${ECHO_CMD} install: >> ${WRKSRC}/man/Makefile

pre-install:
	@${MKDIR} ${PREFIX}/etc/smail

post-install:
.if defined(WITH_REPLACE_CONF)
	@make replace
.endif

.if defined(WITH_CYRUS22) || defined(WITH_CYRUS23)
	@cd ${WRKSRC}/util && make install-cyrus-bins
.endif

.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC}/man && make installman
.endif

replace:
	@${ECHO_MSG} "===> Activating smail in /etc/mail/mailer.conf"
	${MV} -f /etc/mail/mailer.conf /etc/mail/mailer.conf.bak
	@${ECHO_CMD} "#" > /etc/mail/mailer.conf
	@${ECHO_CMD} -n "# Execute the smail sendmail program" >> /etc/mail/mailer.conf
	@${ECHO_CMD} ", named ${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "#" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "sendmail	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "send-mail	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "mailq		${PREFIX}/bin/smail" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "newaliases	${PREFIX}/bin/smail" >> /etc/mail/mailer.conf

.include <bsd.port.post.mk>
