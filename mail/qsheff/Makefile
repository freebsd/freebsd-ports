# New ports collection makefile for:   qsheff
# Date created:                 14 Jul 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	qsheff-II
PORTVERSION=	2.1.r2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A qmail-queue replacement to filter mail traffic

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
RUN_DEPENDS=	${BUILD_DEPENDS}
USE_QMAIL=	yes

GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	README COPYING AUTHORS ChangeLog \
		INSTALL UPGRADE THANKS TODO

OPTIONS=	CLAMAV "Integrate with Clam AntiVirus" on \
			SPAMTAG "Enable Spam Tagging" off \
			VIRUSTAG "Enable Virus Tagging" off \
			DISABLELOCAL "Disable Filters For Local Users" off \
			SYSLOG "Enable Syslog Logging" off \
			BACKUP "Enable Logging Incoming/Outgoing Mail" off \
			CUSTOMERROR "Enable Custom Error Patch" off \
			DEBUG "Enable Debug Messages" off \

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_PREFIX}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
BUILD_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
CONFIGURE_ARGS+=	--with-clamav
CONFIGURE_ARGS+=	--with-clamd-socket=/var/run/clamav/clamd
.endif

.if defined(WITH_SPAMTAG)
CONFIGURE_ARGS+=	--enable-spam-tag
.endif

.if defined(WITH_VIRUSTAG)
CONFIGURE_ARGS+=	--enable-virus-tag
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if defined(WITH_DISABLELOCAL)
CONFIGURE_ARGS+=	--disable-local-users
.endif

.if defined(WITH_BACKUP)
CONFIGURE_ARGS+=	--enable-backup
.endif

.if defined(WITH_CUSTOMERROR)
CONFIGURE_ARGS+=	--enable-custom-error
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS +=|" ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|\(install-data-am: \)install-qsheffdocDATA|\1|g' \
			  -e 's| contribute$$||g' \
		${WRKSRC}/Makefile.in
.endif

post-build:
.if defined(WITHOUT_CLAMAV)
	@${REINPLACE_CMD} -e 's|enable_virus_prog = 1|enable_virus_prog = 0|g' \
		${WRKSRC}/etc/qsheff.conf-default
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/THANKS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@touch ${DOCSDIR}/UPGRADE

.include <bsd.port.post.mk>
