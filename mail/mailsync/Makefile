# Created by: Maxim Tulyuk <mt@primats.org.ua>
# $FreeBSD$

PORTNAME=	mailsync
PORTVERSION=	5.2.1
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keeps collection of mailboxes synchronized

LICENSE=	GPLv2

LIB_DEPENDS=	libc-client4.so:mail/cclient

USES=		autoreconf gmake ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-c-client=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>
# This is a nasty hack due to the weird things that mail/cclient
# do redefining C++ keywords. For some reason GCC seems to build
# this, but we should expect it to break at some point.
# See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=250740
# for reference.
.if ${OPSYS} == FreeBSD && (${OSREL} == 12.2 || ${OSREL} == 11.4)
USE_GCC=	yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mailsync ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mailsync.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS NEWS README \
		THANKS TODO ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ABSTRACT HACKING \
		mail_open_close_flowchart.dia \
		mail_open_close_flowchart.svg \
		mail_open_close_flowchart2.svg ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/mailsync ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
