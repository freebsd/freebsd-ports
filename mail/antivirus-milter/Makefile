# New ports collection makefile for:	antivirus
# Date created:				02.Jan 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	antivirus
PORTVERSION=	3.30
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Sendmail milter wich uses Mcafee Virus Scan or clamav

LICENSE=	BSD

USE_RC_SUBR=	antivirus-milter.sh

CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}
LIBS+=		-lmilter ${PTHREAD_LIBS}
ANTIVIRUS_DIR?=	/var/spool/antivirus
PLIST_SUB+=	ANTIVIRUS=${ANTIVIRUS_DIR}
SUB_LIST+=	ANTIVIRUS=${ANTIVIRUS_DIR}
SED_SCRIPT=	-e 's|%%ANTIVIRUS%%|${ANTIVIRUS_DIR}|g' \
		-e 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
LIBS+=		${LDFLAGS}
.endif
MAKE_ENV+=	SENDMAILBASE="${MILTERBASE}" \
		SENDMAILOBJ="${MILTERBASE}" \
		LIBS="${LIBS}"

do-configure:
	@${REINPLACE_CMD} -e 's|/etc/mail/antivirus.conf|${LOCALBASE}/etc/antivirus.conf|' \
		${CONFIGURE_WRKSRC}/antivirus.c
	@${SED} ${SED_SCRIPT} ${FILESDIR}/antivirus.conf \
		> ${WRKSRC}/antivirus.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/antivirus \
		${PREFIX}/libexec/antivirus
	${INSTALL_DATA} ${WRKSRC}/antivirus.conf ${PREFIX}/etc/antivirus.conf-dist
	${MKDIR} ${ANTIVIRUS_DIR}/spool ${ANTIVIRUS_DIR}/run ${ANTIVIRUS_DIR}/quarantine
	${CHOWN} -R nobody:nobody ${ANTIVIRUS_DIR}/
	@${ECHO_MSG} "Add to your *.mc configfile:"
	@${ECHO_MSG} "INPUT_MAIL_FILTER(\`antivirus', \`S=local:${ANTIVIRUS_DIR}/antivirus.sock, F=')"

.include <bsd.port.post.mk>
