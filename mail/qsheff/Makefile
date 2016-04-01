# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	qsheff-II
DISTVERSION=	2.1-r3
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/ \
		SF/qsheff/qsheff/II-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qmail-queue replacement to filter mail traffic

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:mail/ripmime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		qmail
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qmaildir=${QMAIL_PREFIX}

DOCS=		README AUTHORS ChangeLog INSTALL THANKS TODO
EXAMPLES=	sample-OK.msg sample-SPAM.msg sample-VIRUS.msg
CONTRIB=	README qq-custom-error-patch.diff qq-patch.diff \
		qsheff-patch.diff
FILES=		handbook.en.txt handbook.tr.txt spamass-qsheff.en.html
ETCFILES=	install-wrapper.sh uninstall-wrapper.sh qsheff.attach-default \
		qsheff.conf-default qsheff.ignore-default qsheff.rules-default

OPTIONS_DEFINE=	CLAMAV SPAMTAG VIRUSTAG DISABLELOCAL SYSLOG BACKUP \
		CUSTOMERROR DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=	CLAMAV

CLAMAV_DESC=		Integrate with ClamAV
SPAMTAG_DESC=		Spam tagging
VIRUSTAG_DESC=		Virus tagging
DISABLELOCAL_DESC=	Disable filters for local users
BACKUP_DESC=		Logging of incoming/outgoing mail
CUSTOMERROR_DESC=	Custom error patch

CLAMAV_BUILD_DEPENDS=	${LOCALBASE}/bin/clamdscan:security/clamav
CLAMAV_RUN_DEPENDS=	${CLAMAV_BUILD_DEPENDS}
CLAMAV_CONFIGURE_ON=	--with-clamav --with-clamd-socket=/var/run/clamav/clamd

SPAMTAG_CONFIGURE_ON=	--enable-spam-tag
VIRUSTAG_CONFIGURE_ON=	--enable-virus-tag
SYSLOG_CONFIGURE_ON=	--enable-syslog
DISABLELOCAL_CONFIGURE_ON=--disable-local-users
BACKUP_CONFIGURE_ON=	--enable-backup
CUSTOMERROR_CONFIGURE_ON=--enable-custom-error
DEBUG_CONFIGURE_ON=	--enable-debug

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=""/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/ -ansi//' ${WRKSRC}/src/Makefile.in

post-build-CLAMAV-off:
	@${REINPLACE_CMD} -e '/enable_clamd/s|1|0|' \
		${WRKSRC}/etc/qsheff.conf-default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qsheff ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${ETCFILES:S,^,${WRKSRC}/etc/,} ${STAGEDIR}${ETCDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILES:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/doc

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/samples/,} \
		${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${CONTRIB:S,^,${WRKSRC}/contrib/,} \
		${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.mk>
