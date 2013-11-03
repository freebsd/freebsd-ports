# $FreeBSD$

PORTNAME=	bsmtp
PORTVERSION=	1.02
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	naddy

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Batch SMTP support for sendmail, incoming and outgoing

RUN_DEPENDS=	${LOCALBASE}/bin/uux:${PORTSDIR}/net/freebsd-uucp

CONFLICTS=	smail-3.*

USES=		shebangfix perl5
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--redo
SHEBANG_FILES=	configure

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

privbin=	${STAGEDIR}${PREFIX}/libexec/bsmtp
pubbin= 	${STAGEDIR}${PREFIX}/bin
mailerdir=	${STAGEDIR}${PREFIX}/share/sendmail

do-install:
	${MKDIR} ${privbin}
	${MKDIR} ${mailerdir}
	${INSTALL_PROGRAM} ${WRKSRC}/batcher.new ${privbin}/batcher
	${INSTALL_PROGRAM} ${WRKSRC}/bsmtp ${privbin}
	${INSTALL_DATA} ${WRKSRC}/bsmtp.m4.8.14 ${mailerdir}/bsmtp.m4
	${INSTALL_SCRIPT} ${WRKSRC}/rcsmtp ${pubbin}
.for i in cbsmtp crsmtp rgsmtp
	${LN} -s rcsmtp ${pubbin}/$i
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/rsmtp.wrapper ${pubbin}/rsmtp
	${INSTALL_SCRIPT} ${WRKSRC}/rsmtp ${privbin}
.for i in bsmtp
	${LN} -s rsmtp ${pubbin}/$i
.endfor
.for i in c-cbsmtp c-rcsmtp g-rcsmtp g-rgsmtp n-rsmtp
	${INSTALL_SCRIPT} ${WRKSRC}/transmitter.$i ${privbin}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/_bqueue ${pubbin}
	${INSTALL_SCRIPT} ${WRKSRC}/bqueue ${pubbin}
# post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
