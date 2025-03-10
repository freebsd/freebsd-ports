PORTNAME=	procmail
PORTVERSION=	3.22
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	https://github.com/apple-oss-distributions/procmail/raw/refs/heads/main/ \
		https://ftp.osuosl.org/pub/blfs/conglomeration/procmail/ \
		https://ftp.fu-berlin.de/unix/mail/procmail/ \

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Local mail delivery agent
WWW=		https://github.com/BuGlessRB/procmail

LICENSE=	GPLv2

.if defined(QEMU_EMULATING) && "${QEMU_EMULATING}" == "1"
BROKEN=		fails to build under qemu: killing runaway build after 21600 seconds with no output
.endif

USES=		cpe

EXTRA_PATCHES=	${FILESDIR}/procmail-3.22-getline.patch:-p1
INSTALL_TARGET=	install.bin install.man

PORTDOCS=	FAQ FEATURES HISTORY KNOWN_BUGS README
PORTEXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/config.h ${WRKSRC}/src/autoconf
# Allow parallel builds (-jX) to work
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} -E -e 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|' -e '/^MANDIR/s|/man|/share/man|'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
