# Created by: Neil Blakey-Milner <nbm@rucus.ru.ac.za>

PORTNAME=	ezmlm
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.fu-berlin.de/unix/mail/qmail/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/mail/qmail/ \
		ftp://ftp.gbnet.net/pub/qmail/ \
		ftp://ftp.iway.fr/pub/unix/mail/qmail/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/qmail/ \
		ftp://ftp.archive.de.uu.net/pub/unix/mail/qmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy-to-use, high-speed mailing list manager for qmail

# Converted from LEGAL_TEXT
LICENSE=	djb
LICENSE_NAME=	djb
LICENSE_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		qmail:run

CONFLICTS=	ezmlm-idx

ALL_TARGET=	it

PROGRAMS=	ezmlm-make ezmlm-manage ezmlm-send ezmlm-reject ezmlm-return \
		ezmlm-warn ezmlm-weed ezmlm-list ezmlm-sub ezmlm-unsub
DOCS=		BLURB INSTALL README THANKS TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${ECHO_CMD} "${PREFIX}/bin" > ${WRKSRC}/conf-bin
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}/man" > ${WRKSRC}/conf-man
	@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKSRC}/conf-qmail
	@${REINPLACE_CMD} -e "s:\(/install\) \(\"\`head\):\1 ${STAGEDIR}\2:" \
	    ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${MANPREFIX}/man/man1 && \
		${INSTALL_MAN} *.5 ${STAGEDIR}${MANPREFIX}/man/man5

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
