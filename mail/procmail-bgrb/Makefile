PORTNAME=	procmail
DISTVERSIONPREFIX=	v
DISTVERSION=	3.24
CATEGORIES=	mail
PKGNAMESUFFIX=	-bgrb

MAINTAINER=	cy@FreeBSD.org
COMMENT=	BuGlessRB fork of the procmail local mail delivery agent

USE_GITHUB=	yes
GH_ACCOUNT=	BuGlessRB

CONFLICTS_INSTALL=	procmail

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:net/libnet

.if defined(QEMU_EMULATING) && "${QEMU_EMULATING}" == "1"
BROKEN=		fails to build under qemu: killing runaway build after 21600 seconds with no output
.endif

OPTIONS_DEFINE=	DOCS EXAMPLES

INSTALL_TARGET=	install.bin install.man
USES=		cpe
# EXTRA_PATCHES=	${FILESDIR}/procmail-3.22-getline.patch:-p1

PORTDOCS=	FAQ FEATURES HISTORY KNOWN_BUGS README
PORTEXAMPLES=	1procmailrc 1rmail 2procmailrc 2rmail 3procmailrc 3rmail \
		advanced dirname forward local_procmail_lmtp.m4 mailstat

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/config.h ${WRKSRC}/src/autoconf
# Allow parallel builds (-jX) to work
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
