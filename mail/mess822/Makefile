PORTNAME=	mess822
PORTVERSION=	0.58
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://mirror.pipex.net/pub/unix/mail/qmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC 822 mail message parsing library and rewriting utilities

USES=		groff qmail:vars

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_MTREE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_PREFIX}|" ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${STAGEDIR}${PREFIX} > ${WRKSRC}/conf-home

.include <bsd.port.mk>
