# $FreeBSD$

PORTNAME=	bsmtp
PORTVERSION=	1.02
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	LOCAL/naddy

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Batch SMTP support for sendmail, incoming and outgoing

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/uux:net/freebsd-uucp

CONFLICTS=	smail-3.*

USES=		shebangfix perl5
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--redo
SHEBANG_FILES=	configure

PRIVBIN=	${STAGEDIR}${PREFIX}/libexec/bsmtp
PUBBIN= 	${STAGEDIR}${PREFIX}/bin
MAILERDIR=	${STAGEDIR}${PREFIX}/share/sendmail

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CP} ${WRKSRC}/bsmtp.m4.8.9.in ${WRKSRC}/bsmtp.m4.8.10.in
	@${CP} ${FILESDIR}/bsmtp.m4.8.11.in ${WRKSRC}/
.for v in 12 13 14
	@${CP} ${FILESDIR}/bsmtp.m4.8.12.in ${WRKSRC}/bsmtp.m4.8.$v.in
.endfor

pre-configure:
	@${SED} <${FILESDIR}/config.sed >${WRKSRC}/config.sed \
	    -e 's:%%CC%%:${CC}:' \
	    -e 's:%%CFLAGS%%:${CFLAGS}:' \
	    -e 's:%%PERL%%:${PERL}:' \
	    -e 's:%%PREFIX%%:${PREFIX}:' \
	    -e 's:%%LOCALBASE%%:${LOCALBASE}:'

do-install:
	@${MKDIR} ${PRIVBIN}
	@${MKDIR} ${MAILERDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/batcher.new ${PRIVBIN}/batcher
	${INSTALL_PROGRAM} ${WRKSRC}/bsmtp ${PRIVBIN}
	${INSTALL_DATA} ${WRKSRC}/bsmtp.m4.8.14 ${MAILERDIR}/bsmtp.m4
	${INSTALL_SCRIPT} ${WRKSRC}/rcsmtp ${PUBBIN}
.for i in cbsmtp crsmtp rgsmtp
	${LN} -s rcsmtp ${PUBBIN}/$i
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/rsmtp.wrapper ${PUBBIN}/rsmtp
	${INSTALL_SCRIPT} ${WRKSRC}/rsmtp ${PRIVBIN}
.for i in bsmtp
	${LN} -s rsmtp ${PUBBIN}/$i
.endfor
.for i in c-cbsmtp c-rcsmtp g-rcsmtp g-rgsmtp n-rsmtp
	${INSTALL_SCRIPT} ${WRKSRC}/transmitter.$i ${PRIVBIN}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/_bqueue ${PUBBIN}
	${INSTALL_SCRIPT} ${WRKSRC}/bqueue ${PUBBIN}
	${MKDIR} ${STAGEDIR}/var/spool/bsnmp

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
