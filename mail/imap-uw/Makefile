# Created by: pst
# $FreeBSD$

PORTNAME=	imap
PORTVERSION=	2007f
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/ \
		http://atreides.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	-uw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	University of Washington IMAP4rev1/POP2/POP3 mail servers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libc-client4.so.9:mail/cclient

CONFLICTS_INSTALL=	panda-imap-20*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	bsf

# This port must have the same SSL settings as mail/cclient, which it depends on
# To make MBX format the default mailbox format, change the settings of cclient

OPTIONS_DEFINE=	SSL SSL_AND_PLAINTEXT DRAC NETSCAPE_BRAIN_DAMAGE DOCS
OPTIONS_DEFAULT=	SSL
SSL_DESC=		Compile with SSL support
SSL_AND_PLAINTEXT_DESC=	Allow plain text passwords and SSL
DRAC_DESC=		Dynamically open MTA for relaying
NETSCAPE_BRAIN_DAMAGE_DESC=	See Makefile for documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDRAC}
BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:mail/drac
MAKE_ARGS+=	WITH_DRAC=yes
.endif

.if ! ${PORT_OPTIONS:MSSL}
MAKE_ARGS+=	SSLTYPE=none SSLDIR=${OPENSSLBASE}
.else
USE_OPENSSL=	yes
.if ${PORT_OPTIONS:MSSL_AND_PLAINTEXT}
MAKE_ARGS+=	SSLTYPE=unix
.else
MAKE_ARGS+=	SSLTYPE=unix.nopwd
.endif
.endif

# Define this to get somewhat better interoperability with Netscape.
.if ${PORT_OPTIONS:MNETSCAPE_BRAIN_DAMAGE}
MAKE_ARGS+=	WITH_NETSCAPE_BRAIN_DAMAGE=yes
.endif
# See src/imapd/Makefile for more information about these three options.

.include <bsd.port.pre.mk>
post-patch:
	@${REINPLACE_CMD} -e "s:/etc/c-client.cf:${PREFIX}/etc/c-client.cf:" \
		${WRKSRC}/docs/imaprc.txt
	@${RM} ${WRKSRC}/docs/imaprc.txt.bak

pre-build:
	@${SH} ${PKGREQ}.rev ${LOCALBASE}/include/c-client/portrevision.h ${PORTVERSION}
.if ${PORT_OPTIONS:MSSL}
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h yes
.else
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/mlock/mlock ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${STAGEDIR}${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8 ${STAGEDIR}${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8 ${STAGEDIR}${PREFIX}/man/man8/ipopd.8
	${INSTALL_PROGRAM} ${WRKSRC}/dmail/dmail ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mailutil/mailutil ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tmail/tmail ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/dmail/dmail.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/src/mailutil/mailutil.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/src/tmail/tmail.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install:
	@${CAT} ${PKGMESSAGE}
.if ${PORT_OPTIONS:MDRAC}
	@${ECHO} "================================================================================"
	@${ECHO} "To have DRAC working, you must create ${PREFIX}/etc/dracd.host, containing"
	@${ECHO} "the hostname of the DRAC server:"
	@${ECHO}
	@${ECHO} "localhost"
	@${ECHO} "================================================================================"
.endif
.if ${PORT_OPTIONS:MSSL}
	@${ECHO}
	@${ECHO} "To create and install a new SSL certificate for imapd and ipop3d, type \"make"
	@${ECHO} "cert\". Or install manually in ${PREFIX}/certs."
	@${ECHO}
	@${ECHO} "Example inetd config for SSL only services:"
	@${ECHO}
	@${ECHO} "pop3s   stream  tcp     nowait  root    ${PREFIX}/libexec/ipop3d       ipop3d"
	@${ECHO} "imaps   stream  tcp     nowait  root    ${PREFIX}/libexec/imapd        imapd"
	@${ECHO} "================================================================================"
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} -m 0755 -p ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC}/docs -cf - . | \
		(umask 022; ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -)
.endif

cert:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/certs
	@openssl req -new -x509 -days 365 -nodes -config ${FILESDIR}/imap-uw.cnf -out ${PREFIX}/certs/imapd.pem -keyout ${PREFIX}/certs/imapd.pem
	@openssl x509 -subject -dates -fingerprint -noout -in ${PREFIX}/certs/imapd.pem
	@${CHMOD} 700 ${PREFIX}/certs/imapd.pem
	@${LN} -s ${PREFIX}/certs/imapd.pem ${PREFIX}/certs/ipop3d.pem

.include <bsd.port.post.mk>
