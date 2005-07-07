# New ports collection makefile for:	antivirus
# Date created:				02.Jan 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	antivirus
PORTVERSION=	3.30
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Sendmail milter wich uses Mcafee Virus Scan

RUN_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
.if !defined(SENDMAIL_MILTER_IN_BASE)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
.endif

SENDMAIL_MILTER_PORT?=	sendmail
USE_REINPLACE=	yes
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}
LIBS+=		-lmilter ${PTHREAD_LIBS}
ANTIVIRUS_DIR?=	/var/spool/antivirus
PLIST_SUB+=	ANTIVIRUS=${ANTIVIRUS_DIR}
SED_SCRIPT=	-e 's|%%ANTIVIRUS%%|${ANTIVIRUS_DIR}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g'
MAKE_ENV+=	SENDMAILBASE="${SENDMAILBASE}" \
		SENDMAILOBJ="${SENDMAILOBJ}" \
		LIBS="${LIBS}"

.if !defined(SENDMAIL_MILTER_IN_BASE)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		${LDFLAGS}
SENDMAILBASE=	${LOCALBASE}
SENDMAILOBJ=	${LOCALBASE}
.else
SENDMAILBASE=	/usr
SENDMAILOBJ=	/usr
.endif

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

do-configure:
	@${REINPLACE_CMD} -e 's|/etc/mail/antivirus.conf|${LOCALBASE}/etc/antivirus.conf|' \
		${CONFIGURE_WRKSRC}/antivirus.c
	@${SED} ${SED_SCRIPT} ${FILESDIR}/antivirus-milter.sh \
		> ${WRKSRC}/antivirus-milter.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/antivirus.conf \
		> ${WRKSRC}/antivirus.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/antivirus \
		${PREFIX}/libexec/antivirus
	${INSTALL_SCRIPT} ${WRKSRC}/antivirus-milter.sh \
		${PREFIX}/etc/rc.d/antivirus-milter.sh.sample
	${INSTALL_DATA} ${WRKSRC}/antivirus.conf ${PREFIX}/etc/antivirus.conf-dist
	${MKDIR} ${ANTIVIRUS_DIR}/spool ${ANTIVIRUS_DIR}/run ${ANTIVIRUS_DIR}/quarantine
	${CHOWN} -R nobody:nobody ${ANTIVIRUS_DIR}/
	@${ECHO_MSG} "Add to your *.mc configfile:"
	@${ECHO_MSG} "INPUT_MAIL_FILTER(\`antivirus', \`S=local:${ANTIVIRUS_DIR}/antivirus.sock, F=')"

.include <bsd.port.post.mk>
